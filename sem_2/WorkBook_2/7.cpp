#include <iostream>
using namespace std;

struct Node{
public:
    int value;
    Node* next;
    Node* prev;
};

void append(Node*& head, Node*& tail, int value){
    Node* newNode = new Node;
    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = tail;
    if (!head){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
}

void printList(Node* head){
    Node* current = head;
    while (current){
        cout << current->value;
        if (current->next){
            cout << " <-> ";
        }
        current = current->next;
    }
}


Node* newHead(Node*& head1, Node*& head2){
    Node* cur1 = head1;
    Node* cur2 = head2;

    Node* answerHead = nullptr;
    Node* answerTail = nullptr;

    while (cur1 != nullptr && cur2 != nullptr){
        if(cur1->value < cur2->value){
            cur1 = cur1->next;
        }
        else if (cur1->value > cur2->value){
            cur2 = cur2->next;
        }
        else{
            append(answerHead, answerTail, cur1->value);
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }
    return answerHead;
}

int main(){
    Node* l1Head = nullptr;
    Node* l1Tail = nullptr;
    Node* l2Head = nullptr;
    Node* l2Tail = nullptr;

    // 1 список 
    append(l1Head, l1Tail, 2);
    append(l1Head, l1Tail, 2);
    append(l1Head, l1Tail, 3);
    append(l1Head, l1Tail, 5);
    append(l1Head, l1Tail, 7);
    append(l1Head, l1Tail, 7);
    append(l1Head, l1Tail, 9);
    // 2 список
    append(l2Head, l2Tail, 2);
    append(l2Head, l2Tail, 2);
    append(l2Head, l2Tail, 2);
    append(l2Head, l2Tail, 3);
    append(l2Head, l2Tail, 3);
    append(l2Head, l2Tail, 7);
    append(l2Head, l2Tail, 8);

    Node* ans = newHead(l1Head, l2Head);
    printList(ans);
    cout << endl;
    return 0;
}
