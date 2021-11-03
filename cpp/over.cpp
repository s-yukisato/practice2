#include <iostream>

using namespace std;

template <class T>
T maxt(T x, T y) {
    if (x > y) return x;
    else return y;
}

int main() {
    int a, b;
    double da, db;

    cin >> a >> b >> da >> db;

    int ans = maxt(a, b);
    double dans = maxt(da, da);
}

