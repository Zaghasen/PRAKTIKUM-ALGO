#include <iostream>
using namespace std;

int main()
{
    int X[11] = {20, 50, 10, 30, 90, 60, 70, 80, 40, 100, 110};
    int i, nilaiCari;

    cout << "Nilai yang dicari = ";
    cin >> nilaiCari;

    X[10] = nilaiCari;
    i = 0;

    while (X[i] != nilaiCari)
        i = i + 1;

    if (i < 9)
        cout << nilaiCari << " ditemukan pada index array ke-" << i << endl;
    else
        cout << nilaiCari << " tidak ada dalam Array tersebut" << endl;
}