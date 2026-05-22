#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main(){

    int cntEx = 3;

    vector<int> starts(cntEx);
    vector<int> ends(cntEx);

    for (int i = 0; i < cntEx; i++) {
        cin >> starts[i] >> ends[i];
    }
    
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int i = 0, j = 0, cur = 0, best = 0;

    while (i < cntEx){
        if (j < cntEx && ends[j] <= starts[i]){
            cur--;
            j++;
        }
        else{
            cur++;
            best = max(cur, best);
            i++;
        }
    }

    cout << best;
    return 0;
}
