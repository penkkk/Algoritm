#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Node{
    int l;
    int r;

    Node* left;
    Node* right;

    int maxValue;
    int minValue;
    int sum;
    int odd; //количестов  нечетных
    int even; // количество чет 

    // конструктор для листов
    Node(int l, int r, int val): l(l),
        r(r),
        left(nullptr),
        right(nullptr),
        maxValue(val),
        minValue(val),
        odd(val%2 != 0),
        even(val%2 ==0),
        sum(val)  {}

    Node(int l, int r, Node* leftChild, Node* rightChild) : 
        l(l), r(r), left(leftChild), right(rightChild), 
        sum(leftChild->sum + rightChild->sum),
        maxValue(max(leftChild->maxValue, rightChild->maxValue)),
        minValue(min(leftChild->minValue, rightChild->minValue))
        {
            odd = leftChild->odd + rightChild->odd;
            even = leftChild->even + rightChild->even;
        }
};

Node* buildTree(const vector<int>& arr, int l, int r){
    if (r - l == 1){
        return new Node(l, r, arr[l]);
    }
    int middle = (l + r)/2;
    Node* leftChild = buildTree(arr, l, middle);
    Node* rightChild = buildTree(arr, middle, r);
    return new Node (l, r, leftChild, rightChild);
}


int sumOnInterval(Node* node, int l, int r){
    if (node == nullptr) return 0;

    if (r <= node->l || node->r <= l) return 0;
    if (l <= node->l && node->r <= r) return node->sum;
    return sumOnInterval(node->left, l, r) + sumOnInterval(node->right, l, r);
}



int maxOnInterval(Node* node, int l, int r){
    if (node == nullptr) return INT_MIN;

    if (r <= node->l || node->r <= l) return INT_MIN;
    if (l <= node->l && node->r <= r) return node->maxValue;
    return max(maxOnInterval(node->left, l, r), maxOnInterval(node->right, l, r));
}


int minOnInterval(Node* node, int l, int r){
    if (node == nullptr) return INT_MAX;

    if (r <= node->l || node->r <= l) return INT_MAX;
    if (l <= node->l && node->r <= r) return node->minValue;
    return min(minOnInterval(node->left, l, r), minOnInterval(node->right, l, r));
}

int countOddOnInterval(Node* node, int l, int r){
    if (node == nullptr) return 0;

    if (r <= node->l || node->r <= l) return 0;
    if (l <= node->l && node->r <= r) return node->odd;
    return countOddOnInterval(node->left, l, r) + countOddOnInterval(node->right, l, r);
}

int countEvenOnInterval(Node* node, int l, int r){
    if (node == nullptr) return 0;

    if (r <= node->l || node->r <= l) return 0;
    if (l <= node->l && node->r <= r) return node->even;
    return countEvenOnInterval(node->left, l, r) + countEvenOnInterval(node->right, l, r);
}

int countXDirectByPass(Node* root, int x){
    int count = 0;
    while (root){
        if (root->l <= x && x < root->r){
            count++;
        }
        else break;

        int middle = (root->l + root->r)/2;
        if (x >= middle){
            root = root->right;
        }
        else{
            root = root->left;
        }
    }
    return count;
}

void directByPass(Node* root){
    if (root){
        cout << root->maxValue << " ";
        directByPass(root->left);
        directByPass(root->right);
    }
}



int main(){

    vector<int>arr = {1, 3, 5, 7, 9, 11, 2, 4, 6};
    int size = arr.size();
    
    Node* root = buildTree(arr, 0, size);

    cout << "Сумма всего массива: " << sumOnInterval(root, 0, size) << endl;
    cout << "Сумма на [2, 6): " << sumOnInterval(root, 2, 6) << endl;
    cout << "Количество четных на [2, 6): " << countEvenOnInterval(root, 2, 6) << endl;
    cout << "Количество нечетных на [2, 6): " << countOddOnInterval(root, 2, 6) << endl;
    cout << "Минимальное число на [2, 6): " << minOnInterval(root, 2, 6) << endl;
    cout << "Максимальное число на [2, 6): " << maxOnInterval(root, 2, 6) << endl;
    cout << "Число вхождений числа 4 в интервалах: " << countXDirectByPass(root, 4) << endl;


    return 0;
}
