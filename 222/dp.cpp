#include <iostream>
#include <vector>

using namespace std;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
}

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> weight(N), value(N);
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }

    vector<vector<long long>> dp(N+1, vector<long long>(W+1, 0));
    
}