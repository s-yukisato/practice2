#include<iostream>
#include<cmath>
#include<iomanip>
 
using namespace std;
 
typedef long long ll;
 
int K, R[1 << 10];
double dp[10 + 1][1 << 10];//dp[i][j] := i回戦後、人jが勝ち残ってる確率
 
double win_probability(int P, int Q) {
	double waru = 1.0 + pow(10.0, (double)(R[Q] - R[P]) / 400.0);
	return 1.0 / waru;
}
 
int main() {
	cin >> K;
	for (int i = 0; i < (1 << K); i++)cin >> R[i];

	for (int i = 0; i < (1 << K); i++)dp[0][i] = 1.0;
 
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j < (1 << K); j++) {
			int l = (int)(j / pow(2, i)) * pow(2, i);
			int r = (int)(j / pow(2, i) + 1) * pow(2, i);
			//[l, r)
			for (int k = l; k < r; k++) {
				if (k == j)continue;
				if (((j >> (i - 1)) & 1) == ((k >> (i - 1)) & 1))continue;
				dp[i][j] += (dp[i - 1][j] * dp[i - 1][k]) * win_probability(j, k);
			}
		}
	}
	
	for (int i = 0; i < (1 << K); i++) {
		cout << setprecision(10) << dp[K][i] << endl;
	}
 
	return 0;
}