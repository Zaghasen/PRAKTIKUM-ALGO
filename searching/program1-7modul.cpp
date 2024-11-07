// BinSearch_SudahUrut
/*diasumsikan Array X sudah ada dan berisi data yang sudah terurut, 
nilai yang dicari adalah nilaiCari dan hanya ada satu*/

#include <iostream>
using namespace std;

int main()
{
    int x[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i, nilaiCari, j, k;
    bool found;

    cout << "nilai yang dicari = "; cin >> nilaiCari;

    found = false;
    i = 0;
    j = 10;
    while((!found) & (i <= j))
    {
        k = (i + j) / 2;
        if(nilaiCari == x[k])
        found = true;
        else
        {
            if(nilaiCari < x[k])
            j = k - i; // i tetap
            else
            j = k + i; // j tetap
        }
    }
    if(found)
    cout << nilaiCari << " ditemukan dalam Array pada index ke-" << k << endl;
    else
    cout << "tidak ada " << nilaiCari << " dalam Array" << endl;
}