#include <iostream>
using namespace std;

int main()
{
    int X[10] = {20, 50, 10, 30, 90, 60, 70, 80, 40, 100};
    bool found;
    int i, nilaiCari;

    cout << "Nilai yang dicari = ";
    cin >> nilaiCari;

    found = false;
    i = 0;
    while ((i < 10) & (!found))
    {
        if (X[i] == nilaiCari) // X[4] = 90 == 90
            found = true;
        else
            i = i + 1;
    }

    if (found)
        cout << nilaiCari << " ditemukan pada index array ke-" << i << endl;
    else
        cout << nilaiCari << " tidak ada dalam Array tersebut" << endl;
}