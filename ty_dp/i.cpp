#include <iostream>

using namespace std;

double p[3300];
double dp[3300][3300];


int main () {
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> p[i];

    dp[0][0] = 1.0;

    for(int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j] = dp[i-1][j] * (1.0-p[i]) + dp[i-1][j-1] * p[i];
        }
    }
    double ans = 0.0;
    for (int i = 0; i <= N; i++) {
        if (i > N-i) ans += dp[N][i];
    }
    printf("%.15lf\n", ans);
}