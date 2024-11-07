// melihat isi file secara random
#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    struct
    {
        char judul[26];
        char pengarang[20];
        int jumlah;
    } buku; // variabel buku bertipe structur

    FILE *pf; // ponteer file
    char ulang;
    int nmr_record, hasil_baca;
    long int ofset_byte;

    if((pf = fopen("DAFBUKU.DAT", "rb")) == NULL) // membuka file DAFBUKU.
    {
        cout << "Gagal membuka file DAFBUKU.DAT";
        exit(1);
    }
    ulang = 'Y'; // baca record secara random
    while(ulang == 'Y' || ulang == 'y')
    {
        cout << "\r\n Nomor record dari data yang ingin diketahui : ";
        cin >> nmr_record; cin.ignore();

        ofset_byte = (nmr_record - 1) * sizeof(buku); // menentukan offset
        fseek(pf, ofset_byte, SEEK_SET);
        hasil_baca = fread(&buku, sizeof(buku), 1, pf); // membaca satu record

        if(hasil_baca == 0)
        {
            cout << "\r\n Data yang ingin diketahui tidak ditemukan";
            continue; // kembali ke while
        }
        cout << " Judul buku : " << buku.judul << "\r\n";
        cout << " Judul pengarang : " << buku.pengarang << "\r\n";
        cout << " Judul jumlah buku : " << buku.jumlah << "\r\n";
        cout << "\r\n Mau mencari informasi lagi (Y/T) : ";
        ulang = getchar();
        cout << endl;
    }
    fclose(pf);
}