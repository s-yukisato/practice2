#include <iostream>
#include <vector>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++) 

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    bool flg = false;
    rep(i, H-1) rep(j, W-1) if (A[i][j] + A[i+1][j+1] > A[i][j+1] + A[i+1][j]) flg = true;

    cout << (flg ? "No" : "Yes") << endl;
}