#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main () {
    string S, T;
    cin >> S >> T;
    int N = S.length(), M = T.length();

    vector<vector<int>> dp(N+1, vector<int>(M+1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (S[i-1] == T[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
        }
    }

    string ans = "";
    while (N && M) {
        if (dp[N][M] == dp[N-1][M]) N--;
        else if (dp[N][M] == dp[N][M-1]) M--;
        else {
            N--;
            M--;
            ans = S[N] + ans;
        }
    }

    cout << ans << endl;
}