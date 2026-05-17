#include <iostream>
#include <utility>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;


struct Task
{
    string data;
    int priority;

    Task(string val, int pri) : data(val), priority(pri) {}
};

void heapUp(int index, vector<Task>& array){
    while (index > 0){
        int parent = (index - 1) / 2;
        if (array[parent].priority < array[index].priority){
            swap(array[index], array[parent]);
            index = parent;
        }
        else{
            break;
        }
    }
}

void heapDown(int idx, vector<Task>& array){
    size_t size = array.size();
    while (true)
    {
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        int maximum = idx;

        if (leftChild < size && array[leftChild].priority > array[maximum].priority){
            maximum = leftChild;
        }
        if (rightChild < size && array[rightChild].priority > array[maximum].priority){
            maximum = rightChild;
        }

        if (maximum != idx){
            swap(array[maximum], array[idx]);
            idx = maximum;
        }
        else{
            break;
        }
    }
}


void insert(string nameTask, int priority, vector<Task>& array){
    Task newTask = {nameTask, priority};
    array.push_back(newTask);
    heapUp(array.size() - 1, array);
}


Task extractMax(vector<Task>& array){
    if (array.empty()) throw runtime_error("error");
    else{
        int maximum = array[0].priority;
        string name = array[0].data;
        array[0].priority = array[array.size() - 1].priority;
        array[0].data = array[array.size() - 1].data;
        array.pop_back();
        heapDown(0, array);
        return {name, maximum};
    }
}
