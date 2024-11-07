#include <iostream>
using namespace std;

int main () {
    string Nama = "Zalfa Ghalib Hussein";
    string NIM = "124230097";
    string Hobi = "Mendaki";
    
    string* ptrNama = &Nama;
    string* ptrNIM = &NIM;
    string* ptrHobi = &Hobi;
    
    string* aliasPtrNama = ptrNama;
    string* aliasPtrNIM = ptrNIM;
    string* aliasPtrHobi = ptrHobi;

    cout << "Nama : " << *aliasPtrNama << endl;
    cout << "NIM  : " << *aliasPtrNIM << endl;
    cout << "Hobi : " << *aliasPtrHobi << endl;

}
