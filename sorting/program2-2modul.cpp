// quick_sort

#include <iostream>
#include <stdlib.h>
#define data_size 100
using namespace std;

void quick_sort(int array[], int first, int last) {
    int temp, low, high, list_separator;
    low = first; high = last;
    list_separator = array[(first + last) / 2];
    do {
        while (array[low] < list_separator) low++;      // jika ingin mengganti menjadi terbesar ke terkecil maka "<" dan ">" nya dituker
        while (array[high] > list_separator) high--;    
        if (low <= high) {
            temp = array[low];
            array[low++] = array[high];
            array[high--] = temp;
        }
    } while (low < high);

    if(first < high) quick_sort(array, first, high);
    if(low < last) quick_sort(array, low, last);
}

int main() {
    int first = 0;
    int last = data_size - 1;
    int values[data_size], i;

    // data yang belum diurutkan diambil dari hasil random
    cout << "data yang belum diurutkan : " << endl;
    for (i = 0; i < data_size; i++) {
        values[i] = rand() % 100;
        cout << values[i] << " ";
    }
    cout << endl;

    quick_sort(values, first, last);

    // data yang sudah diurutkan
    cout << "data yang sudah diurutkan : " << endl;
    for (i = 0; i < data_size; i++)
        cout << values[i] << " ";
    getchar();
}
