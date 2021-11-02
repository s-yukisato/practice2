#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> edge[110000];

int memo[110000];
bool done[110000];

int solve(int v) {
    if (done[v]) return memo[v];
    int ans = 0;
    for (int to: edge[v]) {
        ans = max(ans, solve(to) + 1);
    }
    done[v] = true;
    memo[v] = ans;
    return ans;
}


int main () {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, solve(i));
    }
    cout << ans << endl;
}