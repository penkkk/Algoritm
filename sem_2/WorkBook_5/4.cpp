#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

void heapifyUp(int index, vector<int>& array){
    while (index > 0){
        int parent = (index - 1) / 2;
        if (array[parent] > array[index]){
            swap(array[index], array[parent]);
            index = parent;
        }
        else{
            break;
        }
    }
}

void heapDown(int idx, vector<int>& array){
    size_t size = array.size();
    while (true)
    {
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        int minimum = idx;

        if (leftChild < size && array[leftChild] < array[minimum]){
            minimum = leftChild;
        }
        if (rightChild < size && array[rightChild] < array[minimum]){
            minimum = rightChild;
        }

        if (minimum != idx){
            swap(array[minimum], array[idx]);
            idx = minimum;
        }
        else{
            break;
        }
    }
}


int extractMin(vector<int>& array){
    if (!array.empty()){
        int minimal = array[0];
        array[0] = array[array.size() - 1];
        array.pop_back();
        heapDown(0, array);
        return minimal;
    }
    else{
        throw runtime_error("error");
    }
}

void printHeap(vector<int>& array){
    for (int value : array){
        cout << value << ' ';
    }
    cout << endl;
}

void buildHeap(vector<int>& ourHeap){
    for (int i = (ourHeap.size()/2 - 1); i >= 0; i--){
        heapDown(i, ourHeap);
    }    
}

void insert(int data, vector<int>& array){
    array.push_back(data);
    heapifyUp(array.size() - 1, array);
}

int main(){

    vector<int> input{10,13,5,2,6};
    buildHeap(input);
    printHeap(input);
    
    int curSum = 0;
    int total = 0;

    while(input.size() > 1){
        int mn1 = extractMin(input);
        int mn2 = extractMin(input);
        curSum = mn1 + mn2;
        total += curSum;
        cout << "Связываем " << mn1 << " и " << mn2 << " с затратами: " << curSum << endl;
        insert(curSum, input);
    }
    cout << "Общие затраты: " << total << endl;

    return 0;
}
