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

    Node(int l, int r, int val): l(l), r(r), left(nullptr), right(nullptr), maxValue(val) {};

    Node(int l, int r, int val,Node* leftChild, Node* rightChild): 
        l(l), r(r), left(leftChild), right(rightChild), 
        sum(leftChild->sum + rightChild->sum),
        maxValue(max(leftChild->maxValue, rightChild->maxValue)),
        minValue(min(leftChild->minValue, rightChild->minValue)) {}

};

int main(){
    return 0;
}
