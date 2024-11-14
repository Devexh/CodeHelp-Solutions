#include <bits/stdc++.h>
using namespace std; //? TC -> O(nlogn)

void merge(int arr[], int s, int e) {
    int mid = (s+e)/2;
    int lenLeft = mid - s + 1;
    int lenRight = e - mid;

    //create left and right array in heap memory
    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    //copy values from original array to left array
    int k = s;
    //k -> starting index of left array values in original arrays
    for (int i = 0; i < lenLeft; i++) {
        left[i] = arr[k];
        k++;
    }
    //copy values from original array to right array
    k = mid + 1;
    for (int i = 0; i < lenRight; i++) {
        right[i] = arr[k];
        k++;
    }
    //! actual merge logic here
    //left and right arrays are already sorted
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while (leftIndex < lenLeft && rightIndex < lenRight) {
        if(left[leftIndex] < right[rightIndex]) {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++;
            leftIndex++;
        }
        else {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++;
            rightIndex++;
        }
    }

    // 2 more cases, in which either left array will exhaust entirely or right array will
    while (rightIndex < lenRight) {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++;
        rightIndex++;
    }

    while (leftIndex < lenLeft) {
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++;
        leftIndex++;
    }
    //delete the heap memory as it is a good practice to delete the allocated heap memory
    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int s, int e) {
    //base case 
    if (s >= e) {
        return;
    }
    //break
    int mid = (s + e)/2;
    //recursive solution
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    //merge 2 sorted arrays
    merge(arr, s, e);
}

int main() {
    int arr[] = {2,1,6,9,4,5};
    int size = 6;
    int s = 0;
    int e = size - 1;

    cout << "Before merge sort: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    mergeSort(arr, s, e);

    cout << "After merge sort: " << endl;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
