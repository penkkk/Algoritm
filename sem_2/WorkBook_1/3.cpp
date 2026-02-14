#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, int> vote;
    int countStud;
    cin >> countStud;
    int halfStud = countStud / 2 + 1;
    for (int i = 0; i < countStud; i++)
    {
        int voice;
        cin >> voice;
        if (vote[voice])
        {
            vote[voice] = vote[voice] + 1;
        }
        else
        {
            vote[voice] = 1;
        }
    }
    for (auto i: vote)
    {
        if (i.second >= halfStud)
        cout << i.first << endl;
    }
    return 0;
}
