#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    string currentWord = "";
    getline(cin, line);
    line = line + ' ';
    int size = line.size();
    int mx = 0;
    int currentLength = 0;
    for (int i = 0; i < size; i ++)
    {
        if (line[i] != ' ')
        {
            currentLength += 1;
        }
        else
        {
            mx = max(currentLength, mx);
            currentLength = 0;
        }
    }
    for (char c: line)
    {
        if (c != ' ')
        {
            currentWord += c;
        }
        else
        {
            if (currentWord.size() == mx)
            {
                cout << currentWord;
                break;
            }
            currentWord.clear();
        }
    }
    return 0;
}
