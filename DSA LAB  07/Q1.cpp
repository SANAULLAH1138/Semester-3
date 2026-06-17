#include <iostream>
#include <cstring>
using namespace std;

struct Delivery {
    char destination[50];
    int ETA;
};

bool compare(Delivery a, Delivery b) {
    if (a.ETA == b.ETA)
        return strcmp(a.destination, b.destination) < 0;
    return a.ETA < b.ETA;
}

int partition(Delivery arr[], int low, int high) {
    Delivery pivot = arr[high];
    Delivery temp;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compare(arr[j], pivot)) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(Delivery arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Delivery deliveries[4] = {
        {"SANAULLAH STORE ", 120},
        {"HAMZA STORE ", 45},
        {"HASEEB STORE", 90},
        {"HARIS STORE", 45}
    };

    quickSort(deliveries, 0, 3);

    cout << "Sorted Deliveries:\n";
    for (int i = 0; i < 4; i++) {
        cout << deliveries[i].destination << " - " << deliveries[i].ETA << " min\n";
    }

    return 0;
}

