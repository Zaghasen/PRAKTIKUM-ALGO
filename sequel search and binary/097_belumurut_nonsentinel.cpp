#include <iostream>
#include <string>
using namespace std;

struct Telepon {
    string nama;
    int umur;
    string nomor;
};

int main() {
    Telepon telepon[10];
    telepon[0] = {"agung", 21, "572381"};
    telepon[1] = {"ani", 52, "111111"};
    telepon[2] = {"budi", 13, "222222"};
    telepon[3] = {"dengklek", 74, "696969"};
    telepon[4] = {"ganesh", 25, "987123"};
    telepon[5] = {"gareng", 66, "429088"};
    telepon[6] = {"hadi", 79, "682385"};
    telepon[7] = {"joko", 81, "081945"};
    telepon[8] = {"maharani", 19, "212212"};
    telepon[9] = {"wati", 101, "123456"};

    cout << "Daftar Nama :" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << i+1 << ". " << telepon[i].nama << endl;
    }

    string namaCari;
    cout << "\nMasukkan nama yang ingin dicari: ";
    cin >> namaCari;

    bool found = false;
    for (int i = 0; i < 10; ++i) {
        if (telepon[i].nama == namaCari) {
            cout << "Nomor telepon " << namaCari << " adalah " << telepon[i].nomor << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "nihil" << endl;

    return 0;
}
