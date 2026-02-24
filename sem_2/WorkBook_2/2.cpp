#include <iostream>
#include <utility>
using namespace std;

struct Node{
public:
    int data;
    Node* next;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->next = nullptr;

    return node;
};

pair<Node*, Node*> foo(Node* head, int target){
    Node* current = head;
    Node* list1 = nullptr;
    Node* list2 = nullptr;
    while (current != nullptr){
        if (current->data < target){
            Node* list1 = newNode(current->data);      
        }
        else{
            Node* list2 = newNode(current->data);
        }
        current->next;
    }
    return {list1, list2};
}

int main(){
    Node* a1 = newNode(1); Node* a2 = newNode(2); Node* a3 = newNode(3);
    a1->next = a2;
    a2->next = a3;
    auto [a,b] = foo(a1, 2);
    cout << a << ' ' << b;
    return 0;
}

