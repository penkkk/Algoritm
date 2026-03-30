#include <iostream>
#include <vector>
#include <algorithm>
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
    Node(int l, int r, int val): l(l), r(r), left(nullptr), right(nullptr), maxValue(val) {};

    Node(int l, int r, Node* leftChild, Node* rightChild): 
        l(l), r(r), left(leftChild), right(rightChild), 
        sum(leftChild->sum + rightChild->sum),
        maxValue(max(leftChild->maxValue, rightChild->maxValue)),
        minValue(min(leftChild->minValue, rightChild->minValue)) {}
};

Node* buildTree(const vector<int>& arr, int l, int r){
    if (l == r){
        return new Node(l, r, arr[l]);
    }
    int middle = (l + r)/2;
    Node* leftChild = buildTree(arr, l, middle);
    Node* rightChild = buildTree(arr, middle + 1, r);
    return new Node (l, r, leftChild, rightChild);
}

int main(){
    return 0;
}
