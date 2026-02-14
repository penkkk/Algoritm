#include <iostream>
using namespace std;

int foo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n % 10 + foo(n / 10);
    }
}

int main()
{
    int n;
    cin >> n;
    n = abs(n);
    cout << foo(n);
    return 0;
}
