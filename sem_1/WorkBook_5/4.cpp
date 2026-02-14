#include <iostream>
using namespace std;

int foo(int a, int b)
{
    a = abs(a);
    b = abs(b);
    if (a > b)
    {
        return foo(a - b, b);
    }
    else if (a < b)
    {
        return foo(a, b - a);
    }
    else
    {
        return a;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << foo(a, b);
    return 0;
}
