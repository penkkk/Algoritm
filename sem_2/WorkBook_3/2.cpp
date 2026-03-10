#include <iostream>
#include <cmath>
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

int min(int a, int b){
    if (a < b) return a;
    return b;
}

int nearestElement(Node* root, int target){

    if (!root);

    int temp, ans, eps = 1000000;

    while (root){
        temp = root->data;
        eps = min(fabs(temp - target), eps);
        if (fabs(temp - target) == eps){
            ans = temp;
        }
    }
}


int main(){
    int count;
    Node* root = NULL;
    cin >> count;
    for (int i = 0; i < count; i++){
        int data;
        cin >> data;
        root = insert(root, data);
    }
    cout << endl;
    directByPass(root);
    cout << endl;
    int ans = nearestElement(root, 35);
    cout << ans << endl;
    return 0;
}
