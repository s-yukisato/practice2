#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    string ans = "";
    while (true) {
        int x;
        x = N % 26;
        N /= 26;
        if (x == 0) {
            x = 26;
            N -= 1;
        }
        ans = char(x+'a'-1) + ans;
        if (N == 0) break;
    }
    cout << ans << endl;
}