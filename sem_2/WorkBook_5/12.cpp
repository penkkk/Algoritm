#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;


int main(){
    int n, k, t;
    cin >> n >> k >> t;
    vector<int> orders;
    int path;
    for (int i = 0; i < n; i++){
        cin >> path;
        orders.push_back(path);
    }

    sort(orders.begin(), orders.end(), [](int a, int b){
        return a > b;
    });

    vector<int> couries(k);
    for(int i = 0; i < k; i++){
        couries[i] = t;
    }

    int count = 0;

    for (auto i : orders){
        if (i > t) throw runtime_error("Ошибка");

        bool flg = false;
        for (int &j : couries){
            if (j >= i){
                if (j == t) count++;
                j = j - i;
                flg = true;
                break;
            }
        }
        if (!flg) throw runtime_error("Нехватка курьеров");
    }

    cout << count;
    return 0;
}
