#include <iostream>
using namespace std;

int foo(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return foo(n/2);
    }
    else
    {
        return foo((n - 1)/2) + foo((n-1)/2 + 1);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << foo(n);
    return 0;
}
