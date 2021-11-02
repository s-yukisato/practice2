#include <iostream>
#include <vector>
#include <map>

using namespace std;
using ll = long long;

int main()
{
    int N, Q, b, c;
    cin >> N;

    ll sum = 0;
    map<int, int> nums;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (nums.count(A[i]) == 0) {
            nums[A[i]] = 1;
        } else {
            nums[A[i]] += 1;
        }
        sum += A[i];
    }

    cin >> Q;
    int cnt;
    for (int i = 0; i < Q; i++)
    {
        cin >> b >> c;
        
        cnt = nums[b];
        nums[b] = 0;
        if (nums.count(c) == 0) {
            nums[c] = cnt;
        } else {
            nums[c] += cnt;
        }
        sum += cnt * (c - b);
        cout << sum << endl;
    }

    return 0;
}