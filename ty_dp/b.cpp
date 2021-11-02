#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1000000000;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> H(N);
    for (auto& x: H) cin >> x;

    vector<int> dp(N, INF);
    dp[0] = 0;
    for(int i=1; i<N; i++) {
        for (int j=1; j<=K; j++) {
            if (i - j < 0) {
                break;
            }
            dp[i] = min(dp[i], dp[i-j] + abs(H[i] - H[i-j]));
        }
    }
    cout << dp[N-1] << endl;
}