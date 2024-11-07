// menyimpan data dengan putw()

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    FILE *pf;                                       // ptr ke FILE
    int nilai;
    char jawab;

    if((pf == fopen("BILANGAN.twt", "wb")) == NULL) // ciptakan file biner
    {
        cout << "File gagal diciptakan !!\n";
        exit(1);
    }
    cout << "Programa untuk menyimpan data ke integer ke file.";

    do{
        cout << "\r\n Bilangan yang akan disimpan : ";
        cin >> nilai;                               // baca nilai dari keyboard
        cin.ignore();
        putw(nilai, pf);                            // tulis bilangan ke file
        cout << "Masukkan data lagi (Y/T)? : ";
        jawab = getchar();                          // baca jawaban dari keyboard 
    } while(jawab == 'y' || jawab == 'Y');
    fclose(pf); //tutup file
    cout << "\r\nOke. Data sudah disimpan pada file.\r\n";
    getchar();
}