#include <iostream>
using namespace std;

void hanoi(int n, char current, char final, char support)
{
    if (n == 1)
    {
        cout << "Перекладываем 1 диск с " << current << " на " << final << endl;
        return;
    }
    else
    {
        hanoi(n - 1, current, support, final);
        cout << "Переместим диск " << n << " c " << current << " на " << final << endl;
        hanoi(n - 1, support, final, current);
    }
}

int main()
{
    int n;
    cin >> n;
    hanoi(n, 'C', 'F', 'S');
    return 0;
}
