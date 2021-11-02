#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt = 0;
    vector<int> check(3);
    for (int i = 0; i < 3; i++) {
        check[i] = s[i] == 'R';
    }
    if (check[0] && check[1] && check[2]) {
        cout << 3 << endl;
    } else if ((check[0] && check[1]) || (check[1] && check[2])) {
        cout << 2 << endl;
    } else if (check[0] || check[1] || check[2]) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}