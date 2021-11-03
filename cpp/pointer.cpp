#include <iostream>

using namespace std;


void swap(int& x, int& y)
{
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
}

int main()
{
    int a, b;

    a = 5;
    b = 100;

    swap(a, b);

    cout << a << endl;
    cout << b << endl;

    return 0;
}