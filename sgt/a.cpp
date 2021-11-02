#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 2147483647

vector<int> value;
int N;


void update(int idx, int val) {
    idx += N-1;
    value[idx] = val;
    while(idx > 0) {
        idx = (idx-1) / 2;
        value[idx] = min(value[idx*2+1], value[idx*2+2]);
    }
}

int find(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return INF;
    if (a <= l && r <= b) return value[k];
    else {
        int c1 = find(a, b, 2*k+1, l, (l+r)/2);
        int c2 = find(a, b, 2*k+2, (l+r)/2, r);
        return min(c1, c2);
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    N = 1;
    while (N < n) N*= 2;

    value = vector<int>(2*N-1, INF);

    for(int j=0; j<q; j++) {
        int c;
        cin >> c;
        if (c == 0) {
            int i, x;
            cin >> i >> x;
            update(i, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << find(s, t+1, 0, 0, N) << endl; 
        }
    }
    return 0;
}