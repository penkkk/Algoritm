#include <iostream>
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

void printList(Node* head){
    Node* ptr = head;
    while (ptr){
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "nullptr";
}


Node* moving(Node* head){
    Node* cur = head;
    Node* oddDummyHead = nullptr;
    Node* oddDummyTail = nullptr;
    Node* evenDummyHead = nullptr;
    Node* evenDummyTail = nullptr;
    while (cur){
        Node* next = cur->next;
        if (cur->data % 2 == 0){
            if (!evenDummyHead){
                cur->next = nullptr;
                evenDummyHead = evenDummyTail = cur;
            }
            else{
                cur->next = nullptr;
                evenDummyTail->next = cur;
                evenDummyTail = cur;
            }
        }

        else{
            if (!oddDummyHead){
            cur->next = nullptr;
            oddDummyHead = oddDummyTail = cur;
            }
            else{
                cur->next = nullptr;
                oddDummyTail->next = cur;
                oddDummyTail = cur;
            }
        }
        cur = next;
    }
    evenDummyTail->next = oddDummyHead;
    return evenDummyHead;
}


int main(){
    Node* b1 = newNode(5); Node* b2 = newNode(2); Node* b3 = newNode(8); Node* b4 = newNode(3); Node* b5 = newNode(1); Node* b6 = newNode(6);
    b1->next = b2; b2->next = b3; b3->next = b4; b4->next = b5; b5->next = b6;
    printList(b1);
    cout << endl;
    Node* newHead = moving(b1);
    printList(newHead);
}
