#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> prefixFoo(string s)
{
    int size = s.size();
    vector<int> pi(size, 0);
    int j = 0;
    int i = 1;
    while (i < size)
    {
        if (s[i] != s[j])
        {
            if (j == 0)
            {
                pi[i] = 0;
                i++;
            }
            else if(j > 0)
            {
                j = pi[j - 1];
            }
        }
        else
        {
            pi[i] = j + 1;
            i++;
            j++;
        }
    }
    return pi;
}

int main()
{
    string P, S;
    getline(cin, P);
    getline(cin, S);
    int m = P.size(), n = S.size();
    vector<int> pi = prefixFoo(P);
    vector<int> result;
    int j = 0;
    for (int i = 0; i < n; i ++)
    {
        while (j > 0 && S[i] != P[j])
        {
            j = pi[j - 1];
        }
        if (S[i] == P[j])
        {
            j += 1;
        }
        if (P.size() <= j)
        {
            result.push_back(i - j + 1);
        }
    }
    for (int i: result)
    {
        cout << "Подстрака встречается на позиции:";
        cout << i << endl;
    }
    return 0;
}
