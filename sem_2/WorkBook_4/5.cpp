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
    return root;
}



Node* minimumNode(Node* root){
    while(root && root->left) root = root->left;
    return root;
}

void replaceSubtree(Node*& root, Node* firstSubtree, Node* secondSubtree){
    if (!firstSubtree->parent){
        root = secondSubtree;
    }
    else if(firstSubtree == firstSubtree->parent->left){
        firstSubtree->parent->left = secondSubtree;
    }
    else{
        firstSubtree->parent->right = secondSubtree;
    }

    if (secondSubtree){
        secondSubtree->parent = firstSubtree->parent;
    }
}


void fixErase(Node*& root, Node* x){
    while (x != root && (x == nullptr || x->color == 'b')){
        if (x->parent->left == x){
            Node* w = x->parent->right;
            if (w->color == 'r'){
                w->color = 'b';
                w->parent->color = 'r';
                leftRotate(root, x->parent);
                w = x->parent->right;
            }
            else if (w->left->color == 'b' && w->right->color == 'b'){
                w->color = 'r';
                x = x->parent;
            }
            else if (w->left->color == 'r' && w->right->color == 'b'){
                w->color = 'r';
                rotateRight(root, w);
                w = x->parent->right;
            }
            else if (w->right->color == 'r'){
                w->color = x->parent->color;
                x->parent->color = 'b';
                if (w->right) w->right->color = 'b'; 
                leftRotate(root, x->parent);  
                x = root; 
            }
        }
        else { 
            Node* w = x->parent->left;

            if (w && w->color == 'r') {
                w->color = 'b';
                x->parent->color = 'r';
                rotateRight(root, x->parent);
                w = x->parent->left;
            }

            if ((!w->left || w->left->color == 'b') && 
                (!w->right || w->right->color == 'b')) {
                w->color = 'r';
                x = x->parent;
            } else {
                if (!w->left || w->left->color == 'b') {
                    if (w->right) w->right->color = 'b';
                    w->color = 'r';
                    leftRotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = 'b';
                if (w->left) w->left->color = 'b';
                rotateRight(root, x->parent);
                x = root;
            }
        }
    }
    if (x) x->color = 'b';
}


void deleteNode(Node*& root, int data) {
    Node* copyRoot = root;

    
    while (copyRoot) {
        if (data < copyRoot->data) copyRoot = copyRoot->left;
        else if (data > copyRoot->data) copyRoot = copyRoot->right;
        else break;
    }

    if (!copyRoot) return; 

    Node* removeNode = copyRoot; 
    Node* childRemoveNode = nullptr; 
    char originalColor = removeNode->color;

    if (!copyRoot->left) {
        childRemoveNode = copyRoot->right;
        replaceSubtree(root, copyRoot, copyRoot->right);
    }
    
    else if (!copyRoot->right) {
        childRemoveNode = copyRoot->left;
        replaceSubtree(root, copyRoot, copyRoot->left);
    }
    
    else {
        removeNode = minimumNode(copyRoot->right); 
        originalColor = removeNode->color;
        childRemoveNode = removeNode->right;

        if (removeNode->parent == copyRoot) {
            if (childRemoveNode) childRemoveNode->parent = removeNode;
        } else {
            replaceSubtree(root, removeNode, removeNode->right);
            removeNode->right = copyRoot->right;
            removeNode->right->parent = removeNode;
        }

        replaceSubtree(root, copyRoot, removeNode);
        removeNode->left = copyRoot->left;
        removeNode->left->parent = removeNode;
        removeNode->color = copyRoot->color;
    }

    delete copyRoot;

    if (originalColor == 'b') {
        fixErase(root, childRemoveNode);
    }
}



void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << "(" << (root->color == 'r' ? 'r' : 'b') << ") ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;
    
    int arr[] = {7, 3, 18, 10, 22, 8, 11, 26};
    for (int v : arr) root = insert(root, v);
    
    cout << "Inorder: "; inorder(root); cout << endl;
    
    deleteNode(root, 18);
    cout << "После удаления 18: "; inorder(root); cout << endl;
    
    return 0;
}

