#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node{
    int data;
    int balance;
    Node* left;
    Node* right;
};


int max(int a, int b){
    if (a > b) return a;
    return b;
}

int treeHeight(Node* root){
    if (!root) return 0;

    int treeHeightLeft = treeHeight(root->left);
    int treeHeightRight = treeHeight(root->right);

    return max(treeHeightLeft, treeHeightRight) + 1;
}

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->balance = 0;
    return newNode;
}

Node* insert(Node* root, int data){
    if (!root) return createNode(data);
    if (root->data == data) return root;

    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);

    return root;
}

Node* treeFilling(Node* root, int count){
    for (int i = 0; i < count; i++){
        root = insert(root, rand()%100); 
    }
    return root;
}

void directByPass(Node* root){
    if (root){
        cout << root->data << "(" << root->balance << ")" << " ";
        directByPass(root->left);
        directByPass(root->right);
    }
}


void calculateBalance(Node* root){
    if (root){
        root->balance = abs(treeHeight(root->left) - treeHeight(root->right));
        calculateBalance(root->left);
        calculateBalance(root->right);
    }
}



int main(){
    srand(time(NULL));
    int count = 5;
    Node* root = nullptr;
    root = treeFilling(root, count);
    directByPass(root);
    cout << endl;
    calculateBalance(root);
    directByPass(root);
    return 0;
}
