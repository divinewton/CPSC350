#include <iostream>
using namespace std;

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n-1; ++i) {
        for (int j = 0; j < n-i-1; ++j) { // j < n-i-1 -> since the last i elements are already in order
            if (arr[j] > arr[j+1]) { // number of comparisons
                int temp = arr[j];
                arr[j] = arr[j+1]; // number of swaps
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int* arr, int n) {
    int currMinIdx;
    for (int j = 0; j < n-1; ++j) {
        currMinIdx = j;
         for (int k = j+1; k < n; ++k) {
            if (arr[k] < arr[currMinIdx]) {
                currMinIdx = k;
            }
         }
         int temp = arr[j];
         arr[j] = arr[currMinIdx];
         arr[currMinIdx] = temp;
    }
}

void insertionSort(int* arr, int n) {
    for (int j = 1; j < n; ++j) {
        int temp = arr[j];
        int k = j;
        while (k > 0 && arr[k-1] >= temp) {
            arr[k] = arr[k-1];
            --k;
        }
        arr[k] = temp;
    }
}