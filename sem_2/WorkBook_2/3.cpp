#include <iostream>
#include <utility>
using namespace std;

struct Node{
public:
    int value;
    Node* next;
    Node* prev;
};

void append(Node*& head, Node*& tail, int value){ //добавление элемента в конец
    Node* newNode = new Node; // создаем новый узел
    newNode -> value = value;   // создаем новый узел
    if (!head){ // если элементов нет то новый узел становится первым, который указывает сам на себя с двух сторон,
        newNode->next = newNode;
        newNode->prev = newNode;
        head = tail = newNode;
    }
    else{//иначе добавляем после хвоста: элемент становится хвостом указывает на голову меняем хвост
        tail->next = newNode; 
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail = newNode;
    }
}

void printList(Node* head){ // вывод значений
    if (!head){
        return;
    }
    Node* current = head;
    do{
        cout << current->value << " <-> ";
        current = current->next;
    }while(current != head);
    cout << "(head)" << endl;
}


Node* del(Node* head, Node* tail, int target){
    Node* current = head;
    Node* next = current->next;
    while (current != tail){
        if (current->value == target){ //пока не дошли до таргета 
            current->prev->next = current -> next;
            current->next->prev = current -> prev;
            delete current;
            return head;
        }
        current = next;
    }
    return head;
}


int main(){
    Node* head = nullptr;
    Node* tail = nullptr;
    append(head, tail, 1);
    append(head, tail, 2);
    append(head, tail, 4);
    append(head, tail, 3);
    append(head, tail, 5);
    del(head, tail, 2);
    printList(head);
    return 0;
}
