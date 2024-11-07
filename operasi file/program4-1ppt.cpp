// OPERASI FILE DENGAN TIPE DATA STRUCT
#include "bits/stdc++.h"
using namespace std;

struct DataMahasiswa
{
    string nama;
    string nim;
    int umur;
};

string convertSpaceToUnderscore(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            s[i] = '_';
        }
    }

    return s;
}

string convertUnderscoreToSpace(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '_')
        {
            s[i] = ' ';
        }
    }
    return s;
}

int main()
{
    DataMahasiswa mhs[3] = {
        {"Uvuvuevuevue Osas", "1", 25},
        {"Abdul Kocak", "69", 19},
        {"Joko", "19", 45}};
    DataMahasiswa temp[100];
    for (int i = 0; i < 3; i++)
    {
        mhs[i].nama = convertSpaceToUnderscore(mhs[i].nama);
    }

    // Output/tulis data ke file
    ofstream ofs("File Data Mahasiswa.txt", ios::app); // app, out, in
    if (ofs.is_open())
    {
        for (int i = 0; i < 3; i++)
        {
            ofs << left << setw(35) << mhs[i].nama
                << left << setw(10) << mhs[i].nim
                << left << setw(6) << mhs[i].umur
                << endl;
        }
        ofs.close();
    }

    // Input/baca data dari file
    ifstream ifs("File Data Mahasiswa.txt");
    int banyakData = 0;
    if (ifs.is_open())
    {
        int i = 0;
        while (!ifs.eof())
        {
            ifs >> temp[i].nama >> temp[i].nim >> temp[i].umur;
            temp[i].nama = convertUnderscoreToSpace(temp[i].nama);
            i++;
        }
        banyakData = i - 1;

        ifs.close();
    }

    // Menampilkan data dari file
    cout << left << setw(35) << "Nama"
         << left << setw(10) << "NIM"
         << left << setw(6) << "Umur" << endl;
    for (int i = 0; i < banyakData; i++)
    {
        cout << left << setw(35) << temp[i].nama
             << left << setw(10) << temp[i].nim
             << left << setw(6) << temp[i].umur << endl;
    }
}