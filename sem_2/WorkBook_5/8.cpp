#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <iomanip>
using namespace std;


struct Stat {
    long long comparisons = 0; 
    long long swaps = 0;       
    double duration_ms = 0.0;  
};


// Для хипсорта
void heapDown(int idx, vector<int>& ourHeap, size_t ourHeapSize, Stat& stat){
    while (true)
    {
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        int largest = idx;

    
        if (leftChild < ourHeapSize) {
            stat.comparisons++; 
            if (ourHeap[leftChild] > ourHeap[largest]) {
                largest = leftChild;
            }
        }
        if (rightChild < ourHeapSize) {
            stat.comparisons++; 
            if (ourHeap[rightChild] > ourHeap[largest]) {
                largest = rightChild;
            }
        }

        if (largest != idx){
            swap(ourHeap[largest], ourHeap[idx]);
            stat.swaps++; 
            idx = largest;
        }
        else{
            break;
        }
    }
}

void buildHeap(vector<int>& array, Stat& stat){
    if (array.empty()) return;
    size_t arraySize = array.size();
    for (int i = (arraySize/2 - 1); i >= 0; i--){
        heapDown(i, array, arraySize, stat);
    }
}

void heapSort(vector<int>& array, Stat& stat){
    auto start = chrono::high_resolution_clock::now();
    size_t arraySize = array.size();

    buildHeap(array, stat);

    for (int i = arraySize - 1; i > 0; i--){
        swap(array[0], array[i]);
        stat.swaps++;
        heapDown(0, array, i, stat);
    }
    auto end = chrono::high_resolution_clock::now();
    stat.duration_ms = chrono::duration<double, milli>(end - start).count();
}
// конец хипсорта в задание



// далее описаны сортировки

void quickSortInternal(vector<int>& arr, int low, int high, Stat& stat) {
    if (low < high) {
       
        int mid = low + (high - low) / 2;
        int pivot = arr[mid];
        
        int i = low;
        int j = high;
        
        while (i <= j) {
            while (arr[i] < pivot) { stat.comparisons++; i++; }
            while (arr[j] > pivot) { stat.comparisons++; j--; }
            stat.comparisons++; 
            
            if (i < j) { 
                swap(arr[i], arr[j]);
                stat.swaps++;
            }
            
            if (i <= j) {
                i++;
                j--;
            }
        }

        if (low < j) quickSortInternal(arr, low, j, stat);
        if (i < high) quickSortInternal(arr, i, high, stat);
    }
}

void quickSort(vector<int>& arr, Stat& stat) {
    auto start = chrono::high_resolution_clock::now();
    if (!arr.empty()) {
        quickSortInternal(arr, 0, arr.size() - 1, stat);
    }
    auto end = chrono::high_resolution_clock::now();
    stat.duration_ms = chrono::duration<double, milli>(end - start).count();
}


void bubbleSort(vector<int>& arr, Stat& stat) {
    auto start = chrono::high_resolution_clock::now();
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            stat.comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                stat.swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    auto end = chrono::high_resolution_clock::now();
    stat.duration_ms = chrono::duration<double, milli>(end - start).count();
}


void insertionSort(vector<int>& arr, Stat& stat) {
    auto start = chrono::high_resolution_clock::now();
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0) {
            stat.comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                stat.swaps++; 
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
    }
    auto end = chrono::high_resolution_clock::now();
    stat.duration_ms = chrono::duration<double, milli>(end - start).count();
}


void selectionSort(vector<int>& arr, Stat& stat) {
    auto start = chrono::high_resolution_clock::now();
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            stat.comparisons++;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            stat.swaps++;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    stat.duration_ms = chrono::duration<double, milli>(end - start).count();
}


void printRow(string algo, Stat s) {
    cout << setw(15) << left << algo 
         << setw(15) << s.comparisons 
         << setw(15) << s.swaps 
         << setw(15) << fixed << setprecision(4) << s.duration_ms << "\n";
}

void runTests(string testName, const vector<int>& original) {
    cout << "\n=== ТЕСТ: " << testName << " (Размер: " << original.size() << ") ===\n";
    cout << setw(15) << left << "Алгоритм" << setw(15) << "Сравнения" << setw(15) << "Перестановки" << setw(15) << "Время (мс)" << "\n";
    cout << string(60, '-') << "\n";

    vector<int> arr;
    Stat s;

    
    arr = original; s = Stat(); heapSort(arr, s); printRow("Heap Sort", s);

    
    arr = original; s = Stat(); quickSort(arr, s); printRow("Quick Sort", s);


    if (original.size() <= 2000) {
        arr = original; s = Stat(); bubbleSort(arr, s); printRow("Bubble Sort", s);
        arr = original; s = Stat(); insertionSort(arr, s); printRow("Insertion", s);
        arr = original; s = Stat(); selectionSort(arr, s); printRow("Selection", s);
    } else {
        cout << "[Квадратичные сортировки O(N^2) пропущены ради экономии времени]\n";
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    
    const int SMALL_SIZE = 1000;
    const int LARGE_SIZE = 40000;

    
    vector<int> small_partially(SMALL_SIZE);
    for(int i = 0; i < SMALL_SIZE; i++) small_partially[i] = i;
    for(int i = 0; i < SMALL_SIZE; i += 15) {
        if(i + 1 < SMALL_SIZE) swap(small_partially[i], small_partially[i+1]);
    }

    
    vector<int> small_desc(SMALL_SIZE);
    for(int i = 0; i < SMALL_SIZE; i++) small_desc[i] = SMALL_SIZE - i;

    
    vector<int> small_asc(SMALL_SIZE);
    for(int i = 0; i < SMALL_SIZE; i++) small_asc[i] = i;

    
    vector<int> small_rand(SMALL_SIZE);
    mt19937 rng(123); 
    for(int i = 0; i < SMALL_SIZE; i++) small_rand[i] = rng() % 10000;


    vector<int> large_rand(LARGE_SIZE);
    for(int i = 0; i < LARGE_SIZE; i++) large_rand[i] = rng() % 100000;

    
    runTests("Частично отсортирован (1k)", small_partially);
    runTests("По убыванию (1k)", small_desc);
    runTests("По возрастанию (1k)", small_asc);
    runTests("Случайный (1k)", small_rand);
    runTests("Большой случайный (40k)", large_rand);

    return 0;
}
