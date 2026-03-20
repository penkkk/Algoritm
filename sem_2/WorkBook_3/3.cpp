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
