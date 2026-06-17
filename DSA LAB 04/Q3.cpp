#include <iostream>
using namespace std;

// Bubble Sort
void BS(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Linear Search
int LS(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    int arr[] = {29, 10, 14, 37, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 14;

    BS(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    int index = LS(arr, n, target);
    cout << "Target " << target << " found at index: " << index << endl;

    return 0;
}

