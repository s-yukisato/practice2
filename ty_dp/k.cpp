#include <iostream>
#include <vector>

using namespace std;

int A[110];
bool dp[110000];

int main() {
    int N, K;
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i <= K; i++) {
        dp[i] = false;
        for (int j = 0; j < N; j++) {
            dp[i] |= !dp[i - A[j]];
        }
    }
    if (dp[K]) cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}