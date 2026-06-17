#include <iostream>
#include <cstring>
using namespace std;

struct Review {
    int rating;
    char text[100];
};

bool compare(Review a, Review b) {
    if (a.rating == b.rating)
        return strcmp(a.text, b.text) < 0;
    return a.rating > b.rating;
}

void mergeArr(Review arr[], int left, int mid, int right) {
    Review temp[100];
    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (compare(arr[i], arr[j]))
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int x = 0; x < k; x++)
        arr[left + x] = temp[x];
}

void mergeSort(Review arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        mergeArr(arr, left, mid, right);
    }
}

int main() {
    Review reviews[5] = {
        {5, "SUPERB"},
        {3, "GOOD"},
        {5, "EXCELLENT"},
        {4, "NICE"},
        {3, "AVERAGE"}
    };

    mergeSort(reviews, 0, 4);

    cout << "Sorted Reviews:\n";
    for (int i = 0; i < 5; i++) {
        cout << reviews[i].rating << " - " << reviews[i].text << endl;
    }

    return 0;
}


