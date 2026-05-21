#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node (int val, Node* l, Node* r) : data(val), left(l), right(r) {}
};

int countNodes(Node* root) {
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isComplete(Node* root, int idx, int numberNodes) {
    if (root == nullptr) return true;

    if (idx >= numberNodes) return false;

    return isComplete(root->left, 2 * idx + 1, numberNodes) && isComplete(root->right, 2 * idx + 2, numberNodes);
}

bool isMaxHeap(Node* root){
    if (!root) return true;
    
    if (root->left && root->left->data > root->data) return false;

    if (root->right && root->right->data > root->data) return false;

    return isMaxHeap(root->left) && isMaxHeap(root->right);
}


bool isMinHeap(Node* root){
    if (!root) return true;
    
    if (root->left && root->left->data < root->data) return false;

    if (root->right && root->right->data < root->data) return false;

    return isMinHeap(root->left) && isMinHeap(root->right);
}


bool isHeap(Node* root){
    if (root == nullptr) return true;

    int nodeCount = countNodes(root);

    if (!isComplete(root, 0, nodeCount)) {
        return false;
    }

    return isMaxHeap(root) || isMinHeap(root); 
}


int main(){
    return 0;
}
