// membaca sebuah struktur dengan freed{}
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#define JUM_BLOK 1 // sebuah record
using namespace std;

int main()
{
    FILE *f_struktur;
    struct
    {
        char judul[26];
        char pengarang[20];
        int jumlah;
    } buku; // variabel struktur

    if((f_struktur = fopen("DAFBUKU.txt","rb")) == NULL)
    {
        cout << "Gagal membuat file !!\r\n";
        exit(1);
    }
    
    cout << "\nDaftar nuku :\n";
    cout << "\nJudul" << setw(26) << "Pengarang" << setw(20) << "Jumlah\n";

    while(fread(&buku, sizeof(buku), JUM_BLOK, f_struktur) == JUM_BLOK)
    cout << buku.judul << setw(26) << buku.pengarang << setw(20) << buku.jumlah << endl;
    
    fclose(f_struktur);
    getchar();
}