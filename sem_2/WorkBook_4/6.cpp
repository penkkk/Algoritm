#include <iostream>
using namespace std;



struct Node{
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int data) : data(data), right(nullptr), left(nullptr), parent(nullptr) {};
};



void rotateRight(Node*& root, Node* oldMainNode) {
    Node* newMainNode = oldMainNode->left;
    oldMainNode->left = newMainNode->right;
    if (newMainNode->right) newMainNode->right->parent = oldMainNode;
    
    newMainNode->parent = oldMainNode->parent;
    if (!oldMainNode->parent)
        root = newMainNode;
    else if (oldMainNode == oldMainNode->parent->left)
        oldMainNode->parent->left = newMainNode;
    else
        oldMainNode->parent->right = newMainNode;
    
    newMainNode->right = oldMainNode;
    oldMainNode->parent = newMainNode;
}



void rotateLeft(Node*& root, Node* oldMainNode) {
    Node* newMainNode = oldMainNode->right;
    oldMainNode->right = newMainNode->left;
    if (newMainNode->left) newMainNode->left->parent = oldMainNode;
    
    newMainNode->parent = oldMainNode->parent;
    if (!oldMainNode->parent)
        root = newMainNode;
    else if (oldMainNode == oldMainNode->parent->left)
        oldMainNode->parent->left = newMainNode;
    else
        oldMainNode->parent->right = newMainNode;
    
    newMainNode->left = oldMainNode;
    oldMainNode->parent = newMainNode;
}



void splay(Node*& root, Node* node){
    if (!node) return;

    while (node->parent){
        Node* parent = node->parent;
        Node* grandparent = node->parent;

        if (!grandparent){
            if (node == parent->left) { 
                rotateRight(root, node);
             }
             else{
                rotateLeft(root, node);
             }
        }
        else{

            if (node == parent->left && parent == grandparent->left){
                rotateRight(root, grandparent);
                rotateRight(root, parent);
            }
            else if (node == parent->right && parent == grandparent->right){
                rotateLeft(root, grandparent);
                rotateLeft(root, parent);
            }
            else if(node == parent->right && parent == grandparent->left){
                rotateLeft(node, parent);
                rotateRight(node, grandparent);
            }
            else{
                rotateRight(node, parent);
                rotateLeft(node, grandparent);
            }
        }
    }
    root = node;
}



Node* findNode(Node*& root, int data){
    if (!root) return nullptr;

    Node* current = root;
    Node* last = nullptr;

    while(current){
        last = current;
        
        if (data < current->data){
            current = current->left;
        }
        else if (data > current->data){
            current = current->right;
        }
        else{
            splay(root, current);
            return;
        }
    }

    if (last){
        splay(root, last);
    }
    else{
        return nullptr;
    }
}



void insert(Node*& root, int data){

    if (!root) {
        root = new Node(data);
        return;
    }

    Node* parent = nullptr;
    Node* current = root;

    while(current){
        parent = current;
        if (data < current->data){
            current = current->left;
        }
        else if(data > current->data){
            current = current->right;
        }
        else{
            splay(root, current);
            return;
        }
    }

    Node* newNode = new Node(data);
    newNode->parent = parent;

    if (data < parent->data){
        parent->left = newNode;
    }
    else{
        parent->right = newNode;
    }

    splay(root, newNode);
}



Node* findMaximum(Node*& root){
    if (!root) return nullptr;

    while(root) { root = root->right; }
    splay(root, root);
    return root;
}



void deleteNode(Node*& root, int data){
    if (!root) return;

    if (!findNode(root, data)) return;


    delete root;
    Node* leftChild = root->left;
    Node* rightChild = root->right;

    if (!leftChild){
        root = rightChild;
        if (root) root->parent = nullptr;
        return;
    }
    
    if (!rightChild){
        root = leftChild;
        if (root) root->parent = nullptr;
        return;
    }

    leftChild->parent = nullptr;
    rightChild->parent = nullptr;

    root = leftChild;
    Node* leftChildMax = findMaximum(root);

    leftChildMax->right = rightChild;
    rightChild->parent = leftChildMax;

}
