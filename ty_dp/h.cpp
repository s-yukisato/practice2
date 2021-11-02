#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

const int MOD = 1000000007;

string filed[1100];
ll dp[1100][1100];


int main () {
    int H,W;
    cin >> H >> W;
    for(int i = 0; i < H; i++) cin >> filed[i];
    dp[1][0] = 1;

    for(int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
            if (filed[i-1][j-1] == '#') dp[i][j] = 0;
        }
    }

    cout << dp[H][W] << endl;
}