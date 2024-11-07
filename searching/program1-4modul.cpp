// SeqSearch_sudahUrut_NonSentinel
/*diasumsikan array x sudah ada dan berisi data yang suah terurut, nilai yang dicari adalah nilaiCari dan hanya ada satu*/

#include <iostream>
using namespace std;

int main()
{
    int x[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i, nilaiCari;
    bool found;
    
    cout << "Nilai yang dicari = "; 
    cin >> nilaiCari;
    
    found = false;
    i = 0;
    while((i < 10) & (!found) & (nilaiCari >= x[11]))
    {
        if(x[i] == nilaiCari) found = true;
        else i = i + 1;
    }
    if(found)
       cout << nilaiCari << " ditemukan dalam Array pada index ke-" << i << endl;
    else
       cout << "tidak ada " << nilaiCari << " dalam array" << endl;
}