#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int N;
    cin >> N;
    vector<vector<int>> happiness(N, vector<int>(3));
    for (int i = 0; i <N; i++) cin >> happiness[i][0] >> happiness[i][1] >> happiness[i][2];

    vector<vector<int>> dp(N, vector<int>(3));
    dp[0] = happiness[0];
    for (int i = 1; i <N; i++) {
        for (int j = 0; j <3; j++) {
            dp[i][j] = max(dp[i-1][(j+1)%3] + happiness[i][j], dp[i-1][(j+2)%3] + happiness[i][j]);
        }
    }
    cout << *max_element(dp[N-1].begin(), dp[N-1].end()) << endl;
}