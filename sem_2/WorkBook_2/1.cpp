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


bool checkCycle(Node* head) // проверка на зацикленность алгоритмом Флойда (проверка на перескок)
{
    if (!head) return false; // если структура пусат - цикла нет

    Node* slow = head; // указатель который будет за проход делать один шаг
    Node* fast = head; // указатель который будет делать два шага за проход

    while ((fast != nullptr) and (fast->next != nullptr)) // пока у fast есть следующий узел который он может посесить 
    {
        slow = slow->next;          // двигаемя на один шаг
        fast = fast->next->next;    // двигаемся на два шага 

        if (slow == fast) // указатели ссылкаются на один адрес - есть зацикленность, возвращаем true
            return true;            
    }

    return false; 
}

bool checkSlippage(Node* head, int target)
{
    int count = 0; // счётчик узлов
    Node* temp = head; // указываем на начало структуры
    while (temp != nullptr) // пока мы считываем след элемнты
    {
        count++; 
        temp = temp->next; // переход к следующему узлу
    }
    if (count == target) // если количество равно тому которое должно быть в структуре(мы хардкодим его) то проскока нет
    {
        return false;
    }
    return true;
}

bool destinationPointValidation(Node* head)
{
    Node* temp = head; // указываем на начало структуры
    while (temp != nullptr) // пока мы считываем след элемнты
    {
        temp = temp->next; // переход к следующему узлу
    }
    return true; //если цикл завершился без проблем то все коректно
}

bool validate(Node* head, int size)
{
    if ((!checkCycle(head)) && (destinationPointValidation(head)) && (!checkSlippage(head, size)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void runTest(Node* head, int size) {
    bool result = validate(head, size); 
    if (result)
    {
        cout << "ok" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}


int main()
{
    // без ошибок
    Node* a1 = newNode(1); Node* a2 = newNode(2);
    a1->next = a2;
    runTest(a1, 2);

    //Перескок
    Node* b1 = newNode(1); Node* b2 = newNode(2);
    b1->next = b2;
    b2->next = b1;
    runTest(b1, 2);

    // проскок
    Node* c1 = newNode(1); Node* c2 = newNode(2); Node* c3 = newNode(3);
    c1->next = c3; 
    runTest(c1, 3);

    return 0;
}
