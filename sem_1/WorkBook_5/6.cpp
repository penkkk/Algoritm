#include <iostream>
using namespace std;

double f(double x)
{
    return 0.25*x*x*x + x - 2;
}

double foo(double lp = 0.0, double rp = 2.0, double eps = 0.001)
{
    double center = (lp + rp)/2.0;
    if (f(lp) * f(rp) < 0)
    {
        if (rp - lp < eps)
        {
            return center;
        }
        if (f(lp) * f(center) < 0)
        {
            return foo(lp, center, eps);
        }
        else
        {
            return foo(center, rp,eps);
        }
    }
    else 
    {
        cout << "Корня на отрезке нет";
        return 0;
    }
}

int main()
{
    cout << foo();
    return 0;
}
