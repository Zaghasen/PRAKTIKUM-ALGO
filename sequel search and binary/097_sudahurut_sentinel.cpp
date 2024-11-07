#include <iostream>
#include <string>
using namespace std;

struct Telepon {
    string nama;
    int umur;
    string nomor_telepon;
};

int main() {
    Telepon telepon[10] = {
        {"agung", 21, "572381"},
        {"ani", 52, "111111"},
        {"budi", 13, "222222"},
        {"dengklek", 74, "696969"},
        {"ganesh", 25, "987123"},
        {"gareng", 66, "429088"},
        {"hadi", 79, "682385"},
        {"joko", 81, "081945"},
        {"maharani", 19, "212212"},
        {"wati", 101, "123456"}
    };

    cout << "Daftar Nama :" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << i+1 << ". " << telepon[i].nama << endl;
    }

    string namaCari;
    bool found = false;
    int i = 0, j = 9, k;

    cout << "\nNama yang dicari: ";
    cin >> namaCari;

    while ((!found) && (i <= j)) {
        k = (i + j) / 2;
        if (namaCari == telepon[k].nama) {
            found = true;
        } else {
            if (namaCari < telepon[k].nama)
                j = k - 1;
            else
                i = k + 1;
        }
    }

    if (found) {
        cout << "Umur : " << telepon[k].umur << endl;
        cout << "Nomor telepon : " << telepon[k].nomor_telepon << endl;
    } else {
        cout << "Nihil" << endl;
    }

    return 0;
}
