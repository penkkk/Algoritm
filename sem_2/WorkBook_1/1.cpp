#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    int countBadge;
    int badge;
    
    cin >> countBadge;
    unordered_set<int> arr1;

    for (int i = 0; i < countBadge; i ++)
    {
        cin >> badge;
        arr1.insert(badge);
    }
    cin.ignore();
    string returned;
    getline(cin, returned);
    stringstream s(returned);
    unordered_set<int> arr2;
    string v;
    while (s >> v)
    {
        arr2.insert(stoi(v));
    }

    for(int a: arr2)
    {
        arr1.erase(a);
    }
    for (auto i: arr1)
    {
        cout << i << " " << endl;
    }
    return 0;
}


