#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int count;
    cin >> count;
    int mark;
    long long sum = 0;
    vector<int> marks;
    for (int i = 0; i < count; i++)
    {
        cin >> mark;
        marks.push_back(mark);
        sum = sum + mark;
    }

    if (sum % 2 != 0)
    {
        cout << "NO";
        return 0;
    }

    long long target = sum / 2;
    long long p = 0;
    for (auto i: marks)
    {
        p += i;
        if (p == target)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}   
