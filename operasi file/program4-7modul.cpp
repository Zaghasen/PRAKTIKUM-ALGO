// membaca isi file teks dengan fgets()

#include <iostream>
#include <stdlib.h>
#define PANJANG 256
using namespace std;
int main()
{
    FILE *f_teks;
    char string[PANJANG];
    char namafile[65];
    
    cout << "\n PROGRAM UNTUK MELIHAT ISI FILE TEKS\r\n";
    cout << "\n Nama file : "; cin >> namafile;

    if((f_teks = fopen(namafile, "rt")) == NULL) 
    {
        cout << "\n File tidak dapat dibuka\r\n";
        exit(1);
    }

    // baca string dari file selama masih ada
    while((fgets(string, PANJANG, f_teks)) != NULL)
    cout << "\n isi file :\n";
    cout << " " << string << "\r"; //tampilkan string ke layar

    fclose(f_teks);
    getchar();
}