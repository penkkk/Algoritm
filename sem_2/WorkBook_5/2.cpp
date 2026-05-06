#include <iostream>
#include <vector>
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

void insert(int data, vector<int>& array){
    array.push_back(data);
    heapifyUp(array.size() - 1, array);
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
