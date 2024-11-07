// menyimpan data yang diformat ke file, dengan fprint()

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    FILE *pformat;
    char jawab;

    struct
    {
        int x, y;
    } koordinat;
    if((pformat = fopen("koordinat.txt", "w"))==NULL) //buka dan ciptakan file
    {
        cout << "Gagal membuka file";
        exit(1);
    }
    do {
        cout << "\n Masukkan data koordinat (bilangan int)\r\n";
        cout << " Format : Posisi X Posisi Y\r\n";
        cout << " Contoh : 20 30  [ENTER]\r\n\n";
        cin >> koordinat.x >> koordinat.y; cin.ignore();
        fprintf(pformat, "%5d%5d\n", koordinat.x, koordinat.y); //rekam ke file
        
        cout << "Apakah ingin menambahkan koordinat lain? (y/n) : ";
        jawab = getchar(); // baca tombol
    } 
    while (jawab == 'Y' || jawab == 'y');
    fclose(pformat);
}