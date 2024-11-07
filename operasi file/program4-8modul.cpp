// menyalin isi file teks

#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#define PANJANG 256

using namespace std;
void toUp(char *p); // fungsi untuk melakukan uppercase
int main()
{
    FILE *pf_input, *pf_output;
    char string[PANJANG];
    char namafile_inp[65], namafile_out[65];
    
    cout << "\n PROGRAM UNTUK MENYALIN ISI FILE TEKS\r\n";
    cout << "\n HURUF KECIL AKAN DIGANTI HURUF KAPITAL\r\n";
    cout << "\n Nama file input : "; cin >> namafile_inp;
    cout << "\n Nama file output : "; cin >> namafile_out;

    if((pf_input = fopen(namafile_inp, "rt")) == NULL) //buka file input 
    {
        cout << "\n File Input tidak dapat dibuka\r\n";
        exit(1);
    }

    if((pf_output = fopen(namafile_out, "wt")) == NULL) //buka file output 
    {
        cout << "\n File Output tidak dapat dibuka\r\n";
        exit(1);
    }

    // baca string dari file input & konversikan kehuruf kapital
    // kemudian rekam ke file output
    while(fgets(string, PANJANG, pf_input)!= NULL)
    {
        toUp(string);
        fputs(string, pf_output);
    }

    fcloseall(); // tutup dile input dan output
}
void toUp(char *p)
{
    while(*p)
    {
        *p = toupper(*p);
        p++;
    }
}