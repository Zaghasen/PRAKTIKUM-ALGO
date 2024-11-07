#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


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

// Fungsi untuk membaca dan menampilkan data dari file
void outputData() {
    ifstream file("data_kependudukan.txt");

    if (!file) {
        cout << "Gagal membuka file." << endl;
        return;
    }

    DataKependudukan data;
    cout << "Data Kependudukan:" << endl;
    while (file >> data.nomorKependudukan >> data.nama >> data.jenisKelamin) {
        cout << "Nomor Kependudukan: " << data.nomorKependudukan << endl;
        cout << "Nama: " << data.nama << endl;
        cout << "Jenis Kelamin: " << data.jenisKelamin << endl << endl;
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
            cout << "Data ditemukan:" << endl;
            cout << "Nomor Kependudukan: " << data.nomorKependudukan << endl;
            cout << "Nama: " << data.nama << endl;
            cout << "Jenis Kelamin: " << data.jenisKelamin << endl << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Data tidak ditemukan." << endl;
    }

    file.close();
}

// Fungsi untuk melakukan sorting data berdasarkan nomor kependudukan
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
        cout << "MENU PILIHAN:" << endl;
        cout << "a. Input Data" << endl;
        cout << "b. Output Data" << endl;
        cout << "c. Search Data" << endl;
        cout << "d. Sort Data" << endl;
        cout << "e. Exit" << endl;
        cout << "Masukkan pilihan Anda (a-e): ";
        cin >> pilihan;

        switch (pilihan) {
            case 'a':
                inputData();
                break;
            case 'b':
                outputData();
                break;
            case 'c':
                searchData();
                break;
            case 'd':
                sortData();
                break;
            case 'e':
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 'e');

    return 0;
}