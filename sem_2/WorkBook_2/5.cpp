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

Node* reverseList(Node* head){
    Node* current = head;
    Node* prev = nullptr;
    while (current){
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

void printList(Node* head){
    Node* ptr = head;
    while (ptr){
        cout << ptr->data << " -> ";
        ptr = ptr->next;
    }
    cout << "nullptr";
}

void additation(Node* head1, Node* head2){ // сложение стобиком
    // два указателя на две головы 
    Node* cur1 = head1; 
    Node* cur2 = head2;
    int overflow = 0; // переполнение (то что держим в уме)
    while ((cur1) && (cur2)){ // пока и там и там узлы корректны
        int sum = cur1->data + cur2->data + overflow; // сумма узлов
        cur1->data = sum%10; // обновляем значение узла списка который содержит больше эл-тов
        overflow = sum/10; // обновляем переполнение

        if (!cur1->next && overflow){ // ситуация при которой длина большего списка кончилась, то переполнение осталось
            cur1->next = newNode(overflow); //новый узел для большего списка с результатом переполнения
        }

        cur1 = cur1->next;
        cur2 = cur2->next;
    }
    if (cur1 &&  overflow > 0){ // ситуация если больший список не закончился, а меньше кончился, но переполнение осталось от последней операции сложения
        cur1->data += overflow; 
    }
}

int countNode(Node* head){ // подсчёт количества элементов в структуре
    int count = 0;
    Node* current = head;
    while(current){
        count++;
        current = current->next;
    }
    return count;
}

int main(){

    // создание узлов
    Node* a1 = newNode(7); Node* a2 = newNode(2); Node* a3 = newNode(3); Node* a4 = newNode(2); 
    a1->next = a2; a2->next = a3; a3->next = a4;
    Node* b1 = newNode(3); Node* b2 = newNode(2); Node* b3 = newNode(1); Node* b4 = newNode(3); Node* b5 = newNode(2);
    b1->next = b2; b2->next = b3; b3->next = b4; b4->next = b5;

    int count1 = countNode(a1);
    int count2 = countNode(b1);
    
    bool rev = true; // false - числа даны в прямом порядке true - в обратном

    if (!rev){ // если порядок прямой - переворачиваем чтобы удобно сложить столбиком
        a1 = reverseList(a1);
        b1 = reverseList(b1);
    }

    if (count1 > count2){ // выбираем число в котором больше цифр, чтобы записывать результат именно в него
        additation(a1, b1);
        a1 = reverseList(a1);
        printList(a1);
    }
    else{
        additation(b1, a1);
        b1 = reverseList(b1);
        printList(b1);
    }

}


