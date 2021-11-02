#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int A[14] = { 0, 1, 2, 3, 4, 5};
    int *pos;
    int idx;

    pos = lower_bound(A, A+14, 3);
    idx = distance(A, pos);
    
}