#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];

    sort(L.begin(), L.end());

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                if (L[k] + L[j] > L[i]) {
                    cnt += 1;
                }
            }
        }
    }
    cout << cnt << endl;
}