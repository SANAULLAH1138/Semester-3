#include <iostream>
using namespace std;

bool isSubsetSum(int arr[], int n, int index, int target) {
    if (target == 0) {
        return true;
    }
    if (index == n) {
        return false;
    }

    bool exclude = isSubsetSum(arr, n, index + 1, target);

    bool include = false;
    if (arr[index] <= target) {
        include = isSubsetSum(arr, n, index + 1, target - arr[index]);
    }

    if (include || exclude) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = 6;
    int target = 200;

    if (isSubsetSum(arr, n, 0, target)) {
        cout << "True";
    } else {
        cout << "False";
    }

    return 0;
}

