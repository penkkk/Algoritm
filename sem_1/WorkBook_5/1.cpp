#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    string newLine = "";
    string currentWord = "";
    int left = 0;
    getline(cin, line);
    for (char i: line)
    {
        if (i == ' ')
        {
            if (!currentWord.empty())
            {
                newLine = currentWord + ' ' +  newLine;
                currentWord.clear();
            }
        }
        else
        {
            currentWord += i;
        }
    }
    if (!currentWord.empty())
    {
        newLine = currentWord + ' ' +  newLine;
        currentWord.clear();
    }    
    cout << newLine;
}
