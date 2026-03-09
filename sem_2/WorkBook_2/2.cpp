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

pair<Node*, Node*> foo(Node* head, int target){ // функиця возращающая два узла 
    Node* current = head;
    Node* listHead1 = nullptr; Node* listTail1 = nullptr; // создаем два списка где имееем голову и хвост
    Node* listHead2 = nullptr; Node* listTail2 = nullptr;
    while (current){ // проход по начальному списку
        Node* next = current->next; // запоминаем следующий узел
        current->next = nullptr; // отсоединяем текущий узел
        if (current->data < target){ // если меньше нашей цели
            if (!listHead1){ // если список где эл-ты меньше цели пустой то присваеваем и голове и хвосту наше значение
                listHead1 = listTail1 = current;
            }
            else{// елси список не пустой то старый хвост теперь указывает на след узел - наш текуший
                listTail1->next = current; 
                listTail1 = current;
            }
        }
        else{ // аналогично для списка где будут элементы больше таргета
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
    return {listHead1, listHead2}; // возврат двух указателй на голову
}

void printList(Node* head){ // вывод из примера 1
    Node* ptr = head;
    while(ptr){
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << nullptr << endl;
}

int main(){
    Node* a1 = newNode(1); Node* a2 = newNode(2); Node* a3 = newNode(3); // задаем значение узлов
    a1->next = a2;   // раставляем указатели на следующие элементы
    a2->next = a3;   // раставляем указатели на следующие элементы
    auto [a,b] = foo(a1, 2); 
    printList(a); // вывод двух списков
    printList(b);  // вывод двух списков
    return 0;
}

