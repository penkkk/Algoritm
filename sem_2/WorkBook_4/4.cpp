#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct Node{ // структура кч дерева
    int data;
    char color;
    Node* left;
    Node* right; 
};

Node* createNode(int data, char color){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->color = color;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data, char color = 'r'){ //будем создавать обычное бтс, но корень будем красить в черный, все узлы в красный, потому функцией будем проверять выполнение 5 св-тв кч дерева
    if (!root) return createNode(data, 'b'); // корень - черный
    if (root->data == data) return root;

    if (data < root->data) root->left = insert(root->left, data, color); // обычыне узлы красные
    else root->right = insert(root->right, data, color);

    return root;
}

Node* treeFilling(Node* root, int count){
    for (int i = 0; i < count; i++){
        root = insert(root, rand()%100); 
    }
    return root;
}


bool rootIsBlack(Node* root){
    if (!root){
        return true;
    }
    
    if (root->color == 'b'){
        return true;
    }
    else{
        return false;
    }
}

bool nodeIsBlackOrRed(Node* root){
    if (!root){
        return true;
    }

    if (root->color != 'b' || root->color != 'r'){
        return false;
    }

    return nodeIsBlackOrRed(root->left) && nodeIsBlackOrRed(root->right);
}

bool ifNodeRedThenChildBlack(Node* root){
    if (!root){
        return true;
    }


    if (root->color == 'r'){

        if (root->left && root->left->color == 'r'){
            return false;
        }
        
        if (root->right && root->right->color == 'r'){
            return false;
        }
    }

    return ifNodeRedThenChildBlack(root->left) && ifNodeRedThenChildBlack(root->right);
}
