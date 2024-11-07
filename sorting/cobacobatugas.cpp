#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = low + (high - low) / 2;
        int pivot = arr[pivotIndex];
        int i = low;
        int j = high;
        while (i <= j) {
            while (arr[i] < pivot) {
                i++;
            }
            while (arr[j] > pivot) {
                j--;
            }
            if (i <= j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }
        quickSort(arr, low, j);
        quickSort(arr, i, high);
    }
}

int main() {
    srand(time(0));
    vector<int> data(50);
    for (int i = 0; i < 50; i++) {
        data[i] = rand() % 100;
    }
    cout << "50 Data Acak Yang Akan Diurutkan :" << endl;
    for (int i = 0; i < 50; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    cout << "Menu Pilihan :" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Quick Sort" << endl;
    cout << "Pilihan : ";
    int pilihan;
    cin >> pilihan;
    if (pilihan == 1) {
        bubbleSort(data);
    } else if (pilihan == 2) {
        quickSort(data, 0, data.size() - 1);
    } else {
        cout << "Pilihan tidak valid" << endl;
        return 0;
    }
    cout << "50 Data Acak Yang Telah Diurutkan :" << endl;
    for (int i = 0; i < 50; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    cout << "Lagi (y/t) ? ";
    char c;
    cin >> c;
    if (c == 'y' || c == 'Y') {
        main();
    }
    return 0;
}