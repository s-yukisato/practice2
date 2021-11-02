#include <bits/stdc++.h>
using namespace std;
#define rp(i,s,e) for(int i=(s);i<(e);++i)
 
int main(){
	int M; cin>>M;
 
	vector<vector<int>> adj(10); // 1_indexed
	while(M--){
		int u, v; cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
	vector<int> pow10{1};
	rp(i, 0, 9) pow10.push_back(pow10.back()*10);
 
	auto pow10i = [&](int i){ return pow10[9-i]; };
	auto get_digit = [&](int P, int i){ return P % pow10i(i-1) / pow10i(i); };
 
	int start = 999'999'999; // 1_indexed
	rp(j, 1, 9){
		int p; cin>>p; // コマ j の位置情報
		start += (j - 9) * pow10i(p); // 位置 pj にコマ j がある
	}
 
	unordered_map<int,int> dist{{start,0}}; // <頂点=位置情報, 最短距離=操作回数>
	queue<int> que;
	que.push(start);
	while(que.size()){
		int p = que.front(); que.pop();
		int v = to_string(p).find('9') + 1; // 1_indexed
		int V = get_digit(p, v);
		int v_pow10 = pow10i(v);
		for(int&u:adj[v]){
			int U = get_digit(p, u);
			int u_pow10 = pow10i(u);
			int q = p + (U - V) * (v_pow10 - u_pow10);
			if(dist.count(q)) continue; // used
			dist[q] = dist[p] + 1;
			que.push(q);
		}
        cout << dist << endl;
	}
 
	int goal = 123456789; // 位置 j にコマ j がある, 1_indexed
	cout<< (dist.count(goal)? dist[goal]: -1) <<endl;
}