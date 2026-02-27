#include <iostream>
using namespace std;

struct Node
{
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

void insert(Node*& head, Node*& tail, int target, int value){
    Node* current = head;
    Node* newNode = new Node{value, nullptr,nullptr};
    
    while(current){
        if (current->value == target){
            if (!head){
                newNode->next = newNode;
                newNode->prev = newNode;
                head = tail = newNode;
                break;
            }
            else if (current->prev == nullptr){
                newNode -> prev = nullptr;
                newNode -> next = current;
                current -> prev = newNode;
                head = newNode;
                break;
            }
            else{
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
                break;
            }
        }
        current = current->next;
    }
}


void del(Node*& head, Node*& tail, int target){
    Node* current = head;
    while(current){
        Node* nextNode = current->next;
        if (current->value == target){
            if (current->prev == nullptr && current->next == nullptr){
                head = tail = nullptr;
                delete current;
                return;
            }
            else if(current->prev == nullptr){
                head = current->next;
                head -> prev = nullptr;
                delete current;
            }
            else if(current->next == nullptr){
                tail = current->prev;
                tail->next = nullptr;
                delete current;
            }
            else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
        }
        current = nextNode;
    }
}


int countNode(Node*& head){
    int count = 0;
    Node* current = head;
    while(current){
        count++;
        current = current->next;
    }
    return count;
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

void printListReverse(Node* tail){
    Node* current = tail;
    while (current){
        cout << current->value;
        if (current->prev){
            cout << " <-> ";
        }
        current = current->prev;
    }
}


bool is_palindrome(Node*& head, Node*& tail){
    Node* cur1 = head;
    Node* cur2 = tail;
    while (cur1 != cur2){
        if (cur1->value != cur2->value){
            return false;
        }
        cur1 = cur1->next;
        cur2 = cur2->prev;
    }
    return true;
}


int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    append(head, tail, 1);
    append(head, tail, 2);
    append(head, tail, 2);
    append(head, tail, 1);
    cout << is_palindrome(head, tail) << endl;
    printList(head);
    cout << endl;
    insert(head, tail,1,67);
    printList(head);
    cout << endl;
    del(head, tail, 67);
    printList(head);
    cout << endl;
    int c = countNode(head);
    cout << c << endl;
    printListReverse(tail);
    return 0;
}
