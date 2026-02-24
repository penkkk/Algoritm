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
    Node* listHead1 = nullptr; Node* listTail1 = nullptr;
    Node* listHead2 = nullptr; Node* listTail2 = nullptr;
    while (current){
        Node* next = current->next;
        current->next = nullptr;
        if (current->data < target){
            if (!listHead1){
                listHead1 = listTail1 = current;
            }
            else{
                listTail1->next = current;
                listTail1 = current;
            }
        }
        else{
            if (!listHead2){
                listHead2 = listTail2 = current;
            }
            else{
                listTail2->next = current;
                listTail2 = current;
            }
        }
        current = next;
    }
    return {listHead1, listHead2};
}

int main(){
    Node* a1 = newNode(1); Node* a2 = newNode(2); Node* a3 = newNode(3);
    a1->next = a2;
    a2->next = a3;
    auto [a,b] = foo(a1, 2);
    cout << a << ' ' << b;
    return 0;
}

