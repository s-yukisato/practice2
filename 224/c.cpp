#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++) 

int main() {
    int N;
    cin >> N;
    vector<vector<int>> points(N, vector<int>(2));
    rep(i, N) cin >> points[i][0] >> points[i][1];

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            for (int k = j+1; k < N; k++) {
                if ((points[j][1] - points[i][1]) * (points[k][0] - points[i][0])
                    != (points[k][1] - points[i][1]) * (points[j][0] - points[i][0])) cnt++;
            }
        }
    }
    cout << cnt << endl;
}