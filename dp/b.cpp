#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    vector<vector<int>> dp(N+1, vector<int>(M+1));
    dp[N][M] = 0;

    for (int i = N; i > -1; i--) {
        for (int j = M; j > -1; j--) {
            if (i == N && j == M) continue;

            // 先攻の時
            if ((i+j) % 2 == 0) {
                if (i == N) {
                    dp[i][j] = B[j] + dp[i][j+1];
                } else if (j == M) {
                    dp[i][j] = A[i] + dp[i+1][j];
                } else {
                    dp[i][j] = max(B[j] + dp[i][j+1], A[i] + dp[i+1][j]);
                }
            } else {
                if (i == N) {
                    dp[i][j] = dp[i][j+1];
                } else if (j == M) {
                    dp[i][j] = dp[i+1][j];
                } else {
                    dp[i][j] = min(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
    }
    for (int i = 0; i <N+1; i++) {
        for (int j = 0; j < M+1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[0][0] << endl;
}