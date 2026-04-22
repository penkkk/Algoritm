#include <iostream>
#include <utility>
using namespace std;


struct Node{
    int data;
    char color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int data) : data(data), color('r'),
    left(nullptr), right(nullptr), parent(nullptr) {}

};


bool isRed(Node* node) { return node != nullptr && node->color == 'r'; }

bool isBlack (Node* node) { return node == nullptr || node->color == 'b'; }

Node* getGrandparent(Node* node){
    if (node && node->parent->parent)
        return node->parent->parent;
    return nullptr;
}


Node* getUncle(Node* node){
    Node* grandparent = getGrandparent(node);
    if (!grandparent) return nullptr;
    if (node->parent == grandparent->left) return grandparent->right;
    else return grandparent->left;
}


void leftRotate(Node*& root, Node* oldMainNode) {
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

Node* insert(Node* root, int data){
    Node* newNode = new Node(data);
    if (!root) {
        root = newNode;
        root->color = 'b';
        return root;
    }


    Node* current = root;
    Node* parent = nullptr;

    while (current) {
        parent = current;
        if (data < current->data){
            current = current->left;
        }
        else if (data > current->data){
            current = current->right;
        }
        else{
            delete newNode;
            return;
        }
    }
    

    newNode->parent = parent;
    if (data < parent->data){
        parent->left = newNode;
    }
    else{
        parent->right = newNode;
    }

    fixInsert(root, newNode);
}


void fixInsert(Node*& root, Node* node){
    while (node != root && isRed(node->parent)){

        Node* parent = node->parent;
        Node* uncle = getUncle(node);
        Node* grandparent = getGrandparent(node);

        if (isRed(uncle)) {
            parent->color = 'b';
            uncle->color = 'b';
            grandparent->color ='r';
            node = grandparent;
        }
        else{

            if (parent = grandparent->left){
                if (node == parent->right){
                    leftRotate(root, parent);
                    node = parent;
                    parent = node->parent;
                }
                rotateRight(root, grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
            else{
                if (node == parent->left){
                    rotateRight(root, parent);
                    node = parent;
                    parent = node->parent;
                }

                leftRotate(root, grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }

        }
    }
    root->color = 'b';
}

