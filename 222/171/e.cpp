#include <iostream>
#include <vector>

using namespace std;


int main() {
    int N;
    cin >> N;
    vector<int> A(N);

    int B = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        B ^= A[i];
    }
    for (int i = 0; i < N; i++) {
        cout << (B^A[i]) << ' ';
    }
    return 0;
}