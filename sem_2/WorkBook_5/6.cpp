#include <iostream>
#include <utility>
#include <stdexcept>
using namespace std;


struct Node
{
    int data;
    int priority;
    Node* next;

    Node(int val, int prior) : data(val), priority(prior), next(nullptr) {}
};

void insert(Node*& root, int priority, int value){
    Node* newNode = new Node(value, priority);

    if (root == nullptr){
        root = newNode;
    }
    else if (priority < root->priority){
        newNode->next = root;
        root = newNode;
    }
    else{
        Node* cur = root;

        while (cur->next != nullptr && cur->next->priority <= priority){
                cur = cur->next;
            }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

pair<int, int> extractMin (Node*& root){
    if (root == nullptr){
        throw runtime_error("error");
    }
    
    Node* cur = root;

    pair<int,int> minEl = {cur->priority, cur->data};

    root = root->next;
    delete cur;

    return minEl;
}

int main(){
    return 0;
}
