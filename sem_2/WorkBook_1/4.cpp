#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else{
        return b;
    }
}

int main()
{
    int countMark;
    vector<int> marks;
    cin >> countMark;
    for (int i = 0; i < countMark; i++)
    {
        int mark;
        cin >> mark;
        marks.push_back(mark);
    }
    
    int mx = 0, res = 0;
    
    for (int i = 0; i < countMark-1; i ++)
    {
        if (marks[i] == marks[i + 1])
        {
            res++;
        }
        else
        {
            mx = max(mx, res);
            res = 0;
        }
    }
    mx++;
    cout <<  mx << endl;
    return 0;
}
