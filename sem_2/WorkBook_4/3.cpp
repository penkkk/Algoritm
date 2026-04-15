#include <iostream>
#include <cmath>
using namespace std;


struct Node{
    int data;
    unsigned char height;
    Node* right;
    Node* left;

    Node(int val) : 
    data(val),
    right(nullptr),
    left(nullptr),
    height(1) {}

};

void updateHeight(Node* root) {
    if (root == nullptr) return;

    int heightLeft = 0;
    int heightRight = 0;

    if (root->left != nullptr) {
        heightLeft = root->left->height;
    }

    if (root->right != nullptr) {
        heightRight = root->right->height;
    }

    if (heightLeft > heightRight) {
        root->height = heightLeft + 1;
    } 
    else {
        root->height = heightRight + 1;
    }
}


int getBalance(Node* root){
    if (root == nullptr) return 0;

    int heightLeft = 0;
    int heightRight = 0;

    if (root->left != nullptr) {
        heightLeft = root->left->height;
    }

    if (root->right != nullptr) {
        heightRight = root->right->height;
    }
    
    return heightRight - heightLeft;
}


Node* rightRotateCase1(Node* root){
    Node* nextNodeLeft = root->left;
    root->left = nextNodeLeft->right;
    nextNodeLeft->right = root;

    updateHeight(root);
    updateHeight(nextNodeLeft);

    return nextNodeLeft;
}


Node* leftRotateCase2(Node* root){
    Node* nextNodeRight = root->right;
    root->right = nextNodeRight->left;
    nextNodeRight->left = root;

    updateHeight(root);
    updateHeight(nextNodeRight);

    return nextNodeRight;
}



Node* balancedFoo(Node* root){
    if (!root) return nullptr;

    if (getBalance(root) == -2 && getBalance(root->left) == -1){
        return rightRotateCase1(root);
    }
    else if (getBalance(root) == 2 && getBalance(root->right) == 1){
        return leftRotateCase2(root);
    }
    else if(getBalance(root) == -2 && getBalance(root->left) == 1){
        root->left = leftRotateCase2(root->left);
        return rightRotateCase1(root);
    }
    else if(getBalance(root) == 2 && getBalance(root->right) == -1){
        root->right = rightRotateCase1(root->right);
        return leftRotateCase2(root);
    }

    return root;
}


Node* insert(Node* root, int data){
    if (!root) return new Node(data);
    if (root->data == data) return root;

    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);

    updateHeight(root);

    return balancedFoo(root);
}

Node* deleteNode(Node* root, int data){

        if (!root) return NULL;
        
        if (root->data < data){
            root->right = deleteNode(root->right, data);
        }
        else if (root->data > data){
            root->left = deleteNode(root->left, data);
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
                root->data = mxNode->data;
                root->left = deleteNode(root->left, mxNode->data); // из левого поддерева первым случаем удалим зуел со значением которое поставили на место удаляемого
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
                    return balancedFoo(nextRoot);
                }
                else if (root->right == NULL){
                    Node* nextRoot = root->left;
                    delete root;
                    return balancedFoo(nextRoot);
                }
            }
            //=====================

        }
    updateHeight(root);
    return balancedFoo(root);
}
