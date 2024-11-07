#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
void pilihan1();
void pilihan2();
void pilihan3();
void pilihan4();


int i;
struct dataKontrakan{
    int noRumah;
    string namaPemilik;
    string fasilitas;
    int harga;
    string alamat;
}dkontrakan;

int main(){
    int pilihan;
    system("cls");
    cout<<"=== Program Data Rumah Kontrakan ==="<<endl;
    cout<<"Pilihan Menu : "<<endl;
    cout<<"1. Input Data"<<endl;
    cout<<"2. Tambah Data"<<endl;
    cout<<"3. Tampil Data"<<endl;
    cout<<"4. Sorting Data"<<endl;
    cout<<"Pilihan : ";
    cin>>pilihan;
   
       switch (pilihan) {
        case 1:
            pilihan1();
            break;
        case 2:
            pilihan2();
            break;
        case 3:
            pilihan3();
            break;
        // case 4:
        //     pilihan4();
        //     break;        
        default:
            cout << "Pilihan tidak valid." << endl;
    }
    
}

void pilihan1(){
    int banyakData;
    ofstream fileK;
    cout<<"=== Menu Input Data ==="<<endl;
    cout<<"Banyak Data : ";cin>>banyakData;
    
    fileK.open("dataku.txt", ios::out);
    fileK<< left << setfill(' ') << setw(30) << "|Nomor Rumah" << "|"
    << left << setfill(' ') << setw(30) << "Nama Pemilik" << "|"
	<< left << setfill(' ') << setw(30) << "Fasilitas" << "|"
    << left << setfill(' ') << setw(45) << "Alamat" << "|"
    << left << setfill(' ') << setw(15) << "Harga"
    << endl <<endl;
    for(int i=0; i<banyakData; i++){
        cout<<"Nomor Rumah : ";cin>>k[i].noRumah;
        cout<<"Nama Pemilik : ";cin>>k[i].namaPemilik;
        cout<<"Fasilitas : ";cin>>k[i].fasilitas;
        cout<<"Alamat : ";cin>>k[i].alamat;
        cout<<"Harga : ";cin>>k[i].harga;

        fileK<< left << setfill(' ') << setw(30) << k[1].noRumah << "|"
        << left << setfill(' ') << setw(30) << k[i].namaPemilik << "|"
        << left << setfill(' ') << setw(30) << k[i].fasilitas << "|"
        << left << setfill(' ') << setw(45) << k[i].alamat << "|"
        << left << setfill(' ') << setw(15) << k[i].harga
        << endl;
    }
}

void pilihan2(){
    int tambahdata;
    ofstream fileK;
    
    cout<<"=== Menu Tambah Data === "<<endl;
    cout<<"Banyak Data : ";cin>>tambahdata;

    fileK.open("dataku.txt", ios::app);
    fileK<< left << setfill(' ') << setw(30) << "|Nomor Rumah" << "|"
    << left << setfill(' ') << setw(30) << "Nama Pemilik" << "|"
	<< left << setfill(' ') << setw(30) << "Fasilitas" << "|"
    << left << setfill(' ') << setw(45) << "Alamat" << "|"
    << left << setfill(' ') << setw(15) << "Harga"
    << endl <<endl;
    for(int i=0; i<tambahdata; i++){
        cout<<"Nomor Rumah : ";cin>>k[i].noRumah;
        cout<<"Nama Pemilik : ";cin>>k[i].namaPemilik;
        cout<<"Fasilitas : ";cin>>k[i].fasilitas;
        cout<<"Alamat : ";cin>>k[i].alamat;
        cout<<"Harga : ";cin>>k[i].harga;

        fileK<< left << setfill(' ') << setw(30) << k[1].noRumah << "|"
        << left << setfill(' ') << setw(30) << k[i].namaPemilik << "|"
        << left << setfill(' ') << setw(30) << k[i].fasilitas << "|"
        << left << setfill(' ') << setw(45) << k[i].alamat << "|"
        << left << setfill(' ') << setw(15) << k[i].harga
        << endl;
    }



}

void pilihan3() {
    ifstream fileK("dataku.txt");
    if (!fileK.is_open()) {
        cout << "File tidak dapat dibuka" << endl;
        return;
    }

    cout << "=== Menu Tampil Data ===" << endl;
    cout << left << setfill(' ') << setw(30) << "|Nomor Rumah" << "|"
         << left << setfill(' ') << setw(30) << "Nama Pemilik" << "|"
         << left << setfill(' ') << setw(30) << "Fasilitas" << "|"
         << left << setfill(' ') << setw(45) << "Alamat" << "|"
         << left << setfill(' ') << setw(15) << "Harga"
         << endl << endl;

    while (!fileK.eof()) {
        fileK >> k[i].noRumah >> k[i].namaPemilik >> k[i].fasilitas >> k[i].alamat >> k[i].harga;
        cout << left << setfill(' ') << setw(30) << k[i].noRumah << "|"
             << left << setfill(' ') << setw(30) << k[i].namaPemilik << "|"
             << left << setfill(' ') << setw(30) << k[i].fasilitas << "|"
             << left << setfill(' ') << setw(45) << k[i].alamat << "|"
             << left << setfill(' ') << setw(15) << k[i].harga
             << endl;
    }

    fileK.close();
}

