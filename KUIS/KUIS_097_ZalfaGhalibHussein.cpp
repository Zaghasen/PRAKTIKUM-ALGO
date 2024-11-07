#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Struktur data kependudukan
struct DataKependudukan {
    string nomorKependudukan;
    string nama;
    char jenisKelamin;
};

// Fungsi untuk menulis data ke file
void inputData() {
    ofstream file("data_kependudukan.txt", ios::app); // Mode append agar data bertambah jika file sudah ada

    if (!file) {
        cout << "Gagal membuka file." << endl;
        return;
    }

    DataKependudukan data;

    cout << "Masukkan Nomor Kependudukan: ";
    cin >> data.nomorKependudukan;
    cout << "Masukkan Nama: ";
    cin.ignore(); // Membersihkan newline dari buffer
    getline(cin, data.nama);
    cout << "Masukkan Jenis Kelamin (L/P): ";
    cin >> data.jenisKelamin;

    file << data.nomorKependudukan << " " << data.nama << " " << data.jenisKelamin << endl;

    file.close();
}

// Fungsi untuk membaca dan menampilkan semua data (termasuk yang baru diinput) dari file
void outputData() {
    ifstream file("data_kependudukan.txt");

    if (!file) {
        cout << "Gagal membuka file." << endl;
        return;
    }

    DataKependudukan data;
    cout << "Data Kependudukan:" << endl;
    while (file >> data.nomorKependudukan >> data.nama >> data.jenisKelamin) {
        cout << "Nomor Kependudukan : " << data.nomorKependudukan << endl;
        cout << "Nama		   : " << data.nama << endl;
        cout << "Jenis Kelamin	   : " << data.jenisKelamin << endl << endl;
    }
    file.close();
}

// Fungsi untuk mencari data berdasarkan nomor kependudukan
void searchData() {
    string nomor;
    cout << "Masukkan Nomor Kependudukan yang akan dicari: ";
    cin >> nomor;

    ifstream file("data_kependudukan.txt");

    if (!file) {
        cout << "Gagal membuka file." << endl;
        return;
    }
    
    DataKependudukan data;
    bool found = false;
    while (file >> data.nomorKependudukan >> data.nama >> data.jenisKelamin) {
        if (data.nomorKependudukan == nomor) {
			cout << setw(25) << setfill('=')<<""<<endl;
            cout << "Data ditemukan!" << endl;
            cout << setw(25) << setfill('=')<<""<<endl;
            cout << "Nomor Kependudukan : " << data.nomorKependudukan << endl;
			cout << "Nama		   : " << data.nama << endl;
			cout << "Jenis Kelamin	   : " << data.jenisKelamin << endl << endl;
            
            if(data.jenisKelamin != 'P'&&data.jenisKelamin != 'L'){
			}
			file.close();
            
            cout << setw(25) << setfill('=')<<""<<endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Data tidak ditemukan." << endl;
    }
    file.close();
}

void sortData() {
    ifstream file("data_kependudukan.txt");

    if (!file) {
        cout << "Gagal membuka file." << endl;
        return;
    }

    vector<DataKependudukan> dataVector;
    DataKependudukan data;
    while (file >> data.nomorKependudukan >> data.nama >> data.jenisKelamin) {
        dataVector.push_back(data);
    }

    file.close();

    sort(dataVector.begin(), dataVector.end(), [](const DataKependudukan &a, const DataKependudukan &b) {
        return a.nomorKependudukan < b.nomorKependudukan;
    });

    cout << "Data setelah diurutkan berdasarkan Nomor Kependudukan:" << endl;
    for (const auto &item : dataVector) {
        cout << "Nomor Kependudukan: " << item.nomorKependudukan << endl;
        cout << "Nama: " << item.nama << endl;
        cout << "Jenis Kelamin: " << item.jenisKelamin << endl << endl;
    }
}

int main() {
    char pilihan;
    do {
		cout << setw(60) << setfill('=')<<""<<endl;
        cout << setw(50) << setfill(' ') <<"Selamat datang di Kantor Kecamatan Depok!" <<  endl;    
        cout << setw(60) << setfill('=')<<""<<endl;
        cout << setw(40) << setfill(' ')<< "Program Data Kependudukan"<< setfill(' ')<< endl;
        cout << setw(60) << setfill('=')<<""<<endl;
        cout << "MENU PILIHAN:" << endl;
        cout << "1. Input Data" << endl;
        cout << "2. Output Data" << endl;
        cout << "3. Search Data" << endl;
        cout << "4. Sort Data" << endl;
        cout << "5. Exit" << endl;
        cout << "Masukkan pilihan Anda : ";
        cin >> pilihan;

        switch (pilihan) {
				
            case '1':
                inputData();
                break;
            case '2':
                outputData();
                break;
            case '3':
                searchData();
                break;
            case '4':
                sortData();
                break;
            case '5':
                cout << "Terima kasih telah menggunakan program ini." << endl << endl;
                cout << "NAMA : Zalfa Ghalib Hussein" << endl;
				cout << "NIM  : 124230097" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != '5');
    return 0;
}