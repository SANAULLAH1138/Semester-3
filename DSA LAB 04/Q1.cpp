#include <iostream>
using namespace std;

// Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int tar = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > tar) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tar;
    }
}

// Binary Search
int binarySearch(int arr[], int n, int target) {
    int st = 0, end = n - 1;
    while (st <= end) {
        int mid = (st + mid) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) st = mid + 1;
        else end = mid - 1;
    }
    return -1;
}

int main() {
    int arr[] = {34, 7, 23, 32, 5, 62};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    insertionSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int index = binarySearch(arr, n, target);
    cout << "Target " << target << " found at index: " << index << endl;

    return 0;
}

