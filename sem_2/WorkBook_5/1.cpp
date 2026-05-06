#include <iostream>
#include <vector>
using namespace std;

void heapifyUp(int index, vector<int>& array){
    while (index > 0){
        int parent = (index - 1) / 2;
        if (array[parent] < array[index]){
            swap(array[index], array[parent]);
            index = parent;
        }
        else{
            break;
        }
    }
}

void insert(int data, vector<int>& array){
    array.push_back(data);
    heapifyUp(array.size() - 1, array);
}

void printHeap(vector<int>& array){
    for (int value : array){
        cout << value << ' ';
    }
    cout << endl;
}

int main(){
    vector<int> inputArray = {10, 20, 30, 12, 15};
    vector<int> ourHeap;
    for (auto i : inputArray){
        insert(i, ourHeap);
    }

    printHeap(inputArray);
    printHeap(ourHeap);
    return 0;
}
