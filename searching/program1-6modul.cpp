// SeqSearch_SudahUrut_Sentinel (cara 2)
/*diasumsikan array x[1..10] sudah ada dan index 1...9 telah berisi data yang sudah terurut, 
nilai yang dicari adalah nilaiCari dan hanya ada satu*/

#include <iostream>
using namespace std;

int main()
{
    int x[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i, nilaiCari;
    bool found;

    cout << "Nilai yang dicari = "; cin >> nilaiCari;
    x[10] = nilaiCari;
    found = false;
    i = 0;
    while((!found) & (x[i] < nilaiCari))
    {
        if(x[i] == nilaiCari) found = true;
        else i = i + 1;
    }
    if(i == 10)
    cout << "tidak ada " << nilaiCari << " dalam Array" << endl;
    else {
        if(found)
    cout << nilaiCari << " ditemukan dalam Array pada index ke-" << i << endl;
    else
    cout << "tidak ada " << nilaiCari << " dalam array" << endl;
   }
}
