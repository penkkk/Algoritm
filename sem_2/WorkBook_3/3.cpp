#include <iostream>
#include <vector>
#include <string>
using namespace std;



struct Node{
    string name;
    vector<string> phones;
    Node* left;
    Node* right;
};

Node* createNode(string name, vector<string> phones){
    Node* newNode = new Node;
    newNode->name = name;
    newNode->phones = phones;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, string name, vector<string> phones){
    if (!root) return createNode(name, phones);

    if (root->name == name){
        for (auto phone: phones){
            root->phones.push_back(phone);
        }
        return root;
    }

    if(root->name < name){
        root->right = insert(root->right, name, phones);
    }
    else{
        root->left = insert(root->left, name, phones);
    }

    return root;
}

bool searchUser(Node* root, string name){

    if (!root) return false;

    if (root->name == name) return true;
    
    if (root->name < name) return searchUser(root->right, name);
    else return searchUser(root->left, name);
    
}

void searchPhone(Node* root, string name){

    if (root->name == name){
        for (auto phone: root->phones){
            cout << phone << endl;
        }
        return;
    }
    
    if (root->name < name){
        searchPhone(root->right, name);
    }
    else{
        searchPhone(root->left, name);
    }
}

void printPhone(Node* root, string name){
    if (!searchUser(root, name)){
        cout << "Контакт " << name << " отсутствует в телефонной книге." << endl;
    }
    else{
        searchPhone(root, name);
    }
}


Node* deleteNode(Node* root, string name){
        if (!root) return NULL;
        
        if (root->name < name){
            root->right = deleteNode(root->right, name);
        }
        else if (root->name > name){
            root->left = deleteNode(root->left, name);
        }
        else {
            // первый случай
            if (root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            // ==================================

            // второй случай
            else if (root->left && root->right && root->left->right){
                
                Node* mxNode = root->left;
                while (mxNode->right != NULL){
                    mxNode = mxNode->right;
                }
                root->name = mxNode->name;
                root->phones = mxNode->phones;
                root->left = deleteNode(root->left, mxNode->name); // из левого поддерева первым случаем удалим зуел со значением которое поставили на место удаляемого
            }

            // ==================================

            // третий случай
            else if (root->left && root->right && root->left->right == NULL){
                Node* oldRoot = root;
                root = root->left;
                root->right = oldRoot->right;
                delete oldRoot;
            }
            // ==================================

            //четвертый случай
            else{
                if (root->left == NULL){
                    Node* nextRoot = root->right;
                    delete root;
                    return nextRoot;
                }
                else if (root->right == NULL){
                    Node* nextRoot = root->left;
                    delete root;
                    return nextRoot;
                }
            }
            //=====================

        }
    return root;

}


int main(){
    Node* root = NULL;

    while(true){
        cout << "======Телефонная книга=====" << endl;
        cout << "|(1) Добавить контакт     |" << endl;
        cout << "|(2) Найти номер контакта |" << endl;
        cout << "|(3) Удаление контакта    |" << endl;
        cout << "|(0) Выход из программы   |" << endl;
        cout << "===========================" << endl;

        int command;
        cin >> command;
        
        if (command == 0) break;

        switch (command){
            case 1:{

                string name;
                string phone;
                int countPhone;
                vector<string> phones;

                cout << "Введите имя нового контакта: ";
                cin >> name;
                cout << "Введите количество добавляемых номеров для контакта " << name << ": ";
                cin >> countPhone;
                cout << "Введите номера контакта: ";
                for (int i = 0; i < countPhone; i++){
                    cin >> phone;
                    phones.push_back(phone);
                }
                root = insert(root, name, phones);
                cout << "Контакт добавлен в телефонну книжку" << endl;
                break;
            }

            case 2:{
                string name;
                cout << "Введите имя контакта: ";
                cin >> name;
                cout << "Телефоны контакта " << name << ": ";
                printPhone(root, name);
                break;
            }

            case 3:{
                string name;
                cout << "Введите имя контакта для удаления: ";
                cin >> name;
                root = deleteNode(root, name);
                break;
            }

            default:
                break;

        }
    }

    return 0;
}
