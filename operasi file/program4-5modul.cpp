// menyimpan data bertipe struktur, dengan fwrite{}
#include <iostream>
#include <stdlib.h>
using namespace std;
int main(){
    FILE *f_struktur;
    char jawab;
    struct data_pustaka
    {
        char judul[26];
        char pengarang[20];
        int jumlah;
    } buku; // variabel buku bertipe struktur

    if((f_struktur = fopen("DAFBUKU.txt","wb")) == NULL)
    {
        cout << "Gagal membuat file !!\r\n";
        exit(1);
    }
    do {
        cout << "Masukkan judul buku : ";
        cin >> buku.judul;
        cout << "Masukkan pengarang buku : ";
        cin >> buku.pengarang;
        cout << "Masukkan jumlah buku : ";
        cin >> buku.jumlah;
        fwrite(&buku, sizeof(buku), 1, f_struktur);
        cout << "Yakin ingin menambahkan buku lagi? (y/n) : ";
        cin >> jawab;
    } while ((jawab=='y')||(jawab=='Y'));
    fclose(f_struktur); // tutup file
    }