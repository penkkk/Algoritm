#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;    
};

Node* createNode(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data){
    if (!root) return createNode(data);
    if (root->data == data) return root;

    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);

    return root;
}

void directByPass(Node* root){
    if (root){
        cout << root->data << " ";
        directByPass(root->left);
        directByPass(root->right);
    }
}

Node* treeFilling(Node* root, int count){
    for (int i = 0; i < count; i++){
        root = insert(root, rand()%100); 
    }
    return root;
}

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

bool searchElement(Node* root, int data){

    if (!root) return false;

    if (root->data == data) return true;
    
    if (root->data < data) return searchElement(root->right, data);
    else return searchElement(root->left, data);
    
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
    srand(time(NULL));
    int count = 5;
    Node* root = NULL;
    root = treeFilling(root, count);
    root = insert(root, 67);
    directByPass(root);
    cout << endl;
    cout << treeHeight(root) << endl;
    cout << searchElement(root, 67) << endl;

    return 0;
}
