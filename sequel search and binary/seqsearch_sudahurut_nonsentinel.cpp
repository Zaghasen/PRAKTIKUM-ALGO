#include <iostream>
using namespace std;

int main()
{
    int X[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // X[1] = 20 < 90, found = false, 1 < 9

    int i, nilaiCari;

    bool found;

    cout << "Nilai yang dicari = ";
    cin >> nilaiCari;

    found = false;
    i = 0;

    while ((i < 10) & (!found) & (nilaiCari >= X[i]))
    {
        if (X[i] == nilaiCari)
            found = true;
        else
            i = i + 1;
    }

    if (found)
        cout << nilaiCari << " ditemukan pada index array ke-" << i << endl;
    else
        cout << nilaiCari << " tidak ada dalam Array tersebut" << endl;
}