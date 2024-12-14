#include <iostream>
using namespace std;




void bubbleSort(int* arr, int n){
for (int i = 0; i < n-1; ++i){
    for (int j = 0; j < n-i-1; ++j){
        // comparisons made here (n*n), done within nested loops
        if(arr[j] > arr[j+1]){
            // swap them! 
            // swaps made here (n*n worst case), done within nested loops
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
    }
}

}

void selectionSort(int* arr, int n){
    int currMinIdx;
    for (int j = 0; j < n-1; ++j){
        currMinIdx = j;
        for (int k = j + 1; k < n; ++k){
            // comparisons made here (n*n), done within nested loops
            if (arr[k] < arr[currMinIdx]){ 
                // swap... but we need to keep looking in case anything later is smaller 
                currMinIdx = k;
            }
        }
        // swap with min 
        // swaps happen here (O(n) swaps), done outside of nested loop 
        int temp = arr[j];
        arr[j] = arr[currMinIdx];
        arr[currMinIdx] = temp;
    }


}

void insertionSort(int* arr, int n){
for (int j = 1; j < n; ++j){
    int temp = arr[j];
    int k = j; 
    while (k > 0 && arr[k-1] >= temp){
        arr[k] = arr[k-1];
        --k;
    }
    arr[k] = temp;
}

}
 

 /*
	SORTING LECTURE 2
*/

void merge(int* arr, int lo, int hi){
    // not in-place -> we have to allocate a new arr here 
    int* newArr = new int[hi-lo+1];
    int middle = (hi+lo) / 2; 
    int k = 0;
    int i, j; 
    // copy the elements from the sub array to new array 
    for (i = lo; i <= middle; ++i){
        newArr[k++] = arr[i];
    }
    for (j = hi; j>= middle + 1; --j){
        newArr[k++] = arr[j];
    }
    i = 0;
    k = lo;
    j = (hi-lo); // number of elements -1 
    // og       2 4 5  1 3 9  
    // newArr   2 4 5  9 3 1 

    // 1 2 
    // k = 1, 2
    // i = 0, 1 
    // j = j-1 

    while(i <= j){
        if (newArr[i] < newArr[j]){
            arr[k++] = newArr[i++];
        } else {
            arr[k++] = newArr[j--]; 
        }
    }


}

void mergeSort(int* arr, int lo, int hi){
    if (lo < hi){
        int middle = (lo+hi) / 2;
        mergeSort(arr, lo, middle);
        mergeSort(arr, middle+1, hi); 
        merge(arr, lo, hi);
    }
}
 

int partition(int* arr, int lo, int hi){
    int pivot = arr[hi];
    int smallValue = lo-1;
    for (int j = lo; j <= hi-1; ++j){
        if (arr[j] < pivot){
            ++smallValue;
            // swap 
            int temp = arr[j];
            arr[j] = arr[smallValue];
            arr[smallValue] = temp; 
        }
    }
    // put pivot in the right placement
    // by the end of that for loop ^ everything smaller than pivot is at, or to the left of smallValue 
    // and everything that is larger than pivot is to the right of smallValue
    // now, we must place pivot in the correct spot -> between small val and the next thing
    // because the two sides don't need to be in order, just < or > than pivot on either sides
    // we can just swap pivot with smallValue+1 
    int pt = arr[smallValue+1];
    arr[smallValue+1] = arr[hi];
    arr[hi] = pt; 

    return (smallValue+1); // return the pivot 
}


void quickSort(int* arr, int lo, int hi){
    if (lo < hi){
        int partitionIdx = partition(arr, lo, hi);
        quickSort(arr, lo, partitionIdx-1);
        quickSort(arr, partitionIdx+1, hi); 
    }
}