#include <iostream>
#include <vector>
#include <stdexcept>


using namespace std;



class BinaryHeap{
    public:
        vector<int> ourHeap{};
        void heapifyUp(int index){
            while (index > 0){
                int parent = (index - 1) / 2;
                if (ourHeap[parent] < ourHeap[index]){
                    swap(ourHeap[index], ourHeap[parent]);
                    index = parent;
                }
                else{
                    break;
                }
            }
        }

        void heapDown(int idx){
            size_t size = ourHeap.size();
            while (true)
            {
                int leftChild = 2 * idx + 1;
                int rightChild = 2 * idx + 2;
                int large = idx;

                if (leftChild < size && ourHeap[leftChild] > ourHeap[large]){
                    large = leftChild;
                }
                if (rightChild < size && ourHeap[rightChild] > ourHeap[large]){
                    large = rightChild;
                }

                if (large != idx){
                    swap(ourHeap[large], ourHeap[idx]);
                    idx = large;
                }
                else{
                    break;
                }
            }
        }


        BinaryHeap() {};

        BinaryHeap(vector<int>& array) : ourHeap(array) {
            if (ourHeap.empty()) return;

            for (int i = (ourHeap.size()/2 - 1); i >= 0; i--){
                heapDown(i);
            }
        }

        int get_max(){
            if (ourHeap.empty()) throw runtime_error("error");
            else return ourHeap[0];
        }

        int extractMax(){
            if (ourHeap.empty()) throw runtime_error("error");
            else{
                int maximum = ourHeap[0];
                ourHeap[0] = ourHeap[ourHeap.size() - 1];
                ourHeap.pop_back();
                heapDown(0);
                return maximum;
            }
        }

        void insert(int value){
            ourHeap.push_back(value);
            heapifyUp(ourHeap.size() - 1);
        }
};



int main(){
    return 0;
}
