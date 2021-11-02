#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 10000000000;

int main () {
    int N, W;
    cin >> N >> W;
    
    vector<vector<int>> cargo(N, vector<int>(2));
    for (int i = 0; i <N; i++) cin >> cargo[i][0] >> cargo[i][1];

    vector<vector<ll>> dp(N+1, vector<ll>(100000+1, INF));
    dp[0][0] = 0;
    for (int i = 0; i <N; i++) {
        int value = cargo[i][1];
        for (int j = 0; j <100000+1; j++) {
            if (j-value < 0) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = min(dp[i][j], dp[i][j-value] + cargo[i][0]);
        }
    }
    int ans = 0;

    for (int i = 0; i < 100000+1; i++) {
        if (dp[N][i] <= W) {
            ans = max(ans, i);
        }
    }
    cout << ans << endl;
}