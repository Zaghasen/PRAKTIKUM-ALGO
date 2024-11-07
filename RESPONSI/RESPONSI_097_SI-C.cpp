#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
using namespace std;

// Struktur Node
struct Node {
    string namaPelanggan;
    string jenisGadget;
    Node* next;
};

// Kelas untuk Queue
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Menambahkan pelanggan ke antrian pembelian
    void enqueue(string nama, string jenis) {
        Node* temp = new Node;
        temp->namaPelanggan = nama;
        temp->jenisGadget = jenis;
        temp->next = nullptr;

        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }

    // Menghapus pelanggan dari antrian pembelian berdasarkan nama
    void dequeue(string nama = "") {
        if (front == nullptr) {
            cout << "Antrian pembelian kosong." << endl;
            return;
        }

        if (nama == "") {
            Node* temp = front;
            front = front->next;

            if (front == nullptr) {
                rear = nullptr;
            }

            delete temp;
            return;
        }

        Node* current = front;
        Node* previous = nullptr;
        while (current != nullptr && current->namaPelanggan != nama) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Nama pelanggan tidak ditemukan." << endl;
            return;
        }

        if (previous == nullptr) {
            front = current->next;
        } else {
            previous->next = current->next;
        }

        if (current == rear) {
            rear = previous;
        }

        delete current;
    }

    // Menampilkan antrian pembelian
    void display() {
        if (front == nullptr) {
            cout << "Antrian pembelian kosong." << endl;
            return;
        }

        Node* temp = front;
        vector<string> names;
        int count = 0;
        while (temp != nullptr) {
            names.push_back(temp->namaPelanggan);
            temp = temp->next;
            count++;
        }

        cout << setw(40) << setfill('=') << "" << endl;
        cout << "Jumlah Pembelian : " << count << endl;
        cout << "Dengan nama : ";
        for (const string& name : names) {
            cout << name << ", ";
        }
        cout << endl;
        cout << setw(40) << setfill('=') << "" << endl;
    }

    // Menampilkan daftar nama dalam antrian pembelian
    void displayNames() {
        if (front == nullptr) {
            cout << "Antrian pembelian kosong." << endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->namaPelanggan << endl;
            temp = temp->next;
        }
    }

    // Menyimpan antrian pembelian ke file
    void saveToFile(ofstream &file) {
        Node* temp = front;
        file << "Antrian Pembelian:" << endl;
        while (temp != nullptr) {
            file << "Nama : " << temp->namaPelanggan << ", Gadget : " << temp->jenisGadget << endl;
            temp = temp->next;
        }
    }
};

// Kelas untuk Stack
class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }

    // Menambahkan pelanggan ke antrian pengembalian
    void push(string nama, string jenis) {
        Node* temp = new Node;
        temp->namaPelanggan = nama;
        temp->jenisGadget = jenis;
        temp->next = top;
        top = temp;
    }

    // Menghapus pelanggan dari antrian pengembalian berdasarkan nama
    void pop(string nama = "") {
        if (top == nullptr) {
            cout << "Antrian pengembalian kosong." << endl;
            return;
        }

        if (nama == "") {
            Node* temp = top;
            top = top->next;
            delete temp;
            return;
        }

        Node* current = top;
        Node* previous = nullptr;
        while (current != nullptr && current->namaPelanggan != nama) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Nama pelanggan tidak ditemukan." << endl;
            return;
        }

        if (previous == nullptr) {
            top = current->next;
        } else {
            previous->next = current->next;
        }

        delete current;
    }

    // Menampilkan antrian pengembalian
    void display() {
        if (top == nullptr) {
            cout << "Antrian pengembalian kosong." << endl;
            return;
        }

        Node* temp = top;
        cout << setw(40) << setfill('=') << "" << endl;
        cout << "PENGEMBALIAN:" << endl;
        cout << setw(40) << setfill('=') << "" << endl;
        while (temp != nullptr) {
            cout << "Nama: " << temp->namaPelanggan << endl;
            cout << "Barang: " << temp->jenisGadget << endl;
            temp = temp->next;
            cout << setw(40) << setfill('=') << "" << endl;
        }
    }

    // Menampilkan daftar nama dalam antrian pengembalian
    void displayNames() {
        if (top == nullptr) {
            cout << "Antrian pengembalian kosong." << endl;
            return;
        }

        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->namaPelanggan << endl;
            temp = temp->next;
        }
    }

    // Menyimpan antrian pengembalian ke file
    void saveToFile(ofstream &file) {
        Node* temp = top;
        file << "Antrian Pengembalian:" << endl;
        while (temp != nullptr) {
            file << "Nama: " << temp->namaPelanggan << ", Gadget: " << temp->jenisGadget << endl;
            temp = temp->next;
        }
    }
};

// Fungsi utama
int main() {
    Queue pembelian;
    Stack pengembalian;
    int pilihan;
    string nama, jenis;
    ofstream file;

    cout << "Masukkan nama file untuk menyimpan data: ";
    string filename;
    cin >> filename;
    file.open(filename);

    if (!file.is_open()) {
        cout << "Error membuka file." << endl;
        return 1;
    }

    do {
        cout << setw(60) << setfill('=') << "" << endl;
        cout << setw(40) << setfill(' ') << "SISTEM ANTREAN SENTRAL GADGET" << setfill(' ') << endl;
        cout << setw(60) << setfill('=') << "" << endl;
        cout << "\nMenu:\n";
        cout << "1. Tambah pelanggan\n";
        cout << "2. Tampilkan antrian pembelian\n";
        cout << "3. Tampilkan antrian pengembalian\n";
        cout << "4. Hapus pelanggan dari antrian\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer input

        switch (pilihan) {
            case 1:
                cout << "Nama pelanggan : ";
                getline(cin, nama);
                cout << "Pembelian (P) atau Pengembalian (R)? ";
                char tipeAntrian;
                cin >> tipeAntrian;
                cin.ignore(); // Membersihkan buffer input
                if (tipeAntrian == 'P' || tipeAntrian == 'p') {
                    cout << "Jenis gadget";
                    cout << "\n- HP";
                    cout << "\n- Laptop";
                    cout << "\n- Aksesoris";
                    cout << "\nPilihan : ";
                    getline(cin, jenis);
                    pembelian.enqueue(nama, jenis);
                } else if (tipeAntrian == 'R' || tipeAntrian == 'r') {
                    cout << "Jenis gadget";
                    cout << "\n- HP";
                    cout << "\n- Laptop";
                    cout << "\n- Aksesoris";
                    cout << "\nPilihan : ";
                    getline(cin, jenis);
                    pengembalian.push(nama, jenis);
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }
                break;
            case 2:
                cout << "Antrian pembelian:" << endl;
                pembelian.display();
                break;
            case 3:
                cout << "Antrian pengembalian:" << endl;
                pengembalian.display();
                break;
            case 4:
                cout << "Hapus dari Pembelian (P) atau Pengembalian (R)? ";
                cin >> tipeAntrian;
                cin.ignore(); // Membersihkan buffer input
                if (tipeAntrian == 'P' || tipeAntrian == 'p') {
                    cout << setw(60) << setfill('=') << "" << endl;
                    cout << "Pilih nama pelanggan yang akan dihapus : " << endl;
                    pembelian.displayNames();
                    cout << "Nama pelanggan : ";
                    getline(cin, nama);
                    pembelian.dequeue(nama);
                    cout << setw(60) << setfill('=') << "" << endl;
                } else if (tipeAntrian == 'R' || tipeAntrian == 'r') {
                    cout << setw(60) << setfill('=') << "" << endl;
                    cout << "Pilih nama pelanggan yang akan dihapus: " << endl;
                    pengembalian.displayNames();
                    cout << "Nama pelanggan: ";
                    getline(cin, nama);
                    pengembalian.pop(nama);
                    cout << setw(60) << setfill('=') << "" << endl;
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }
                break;
            case 5:
                cout << setw(60) << setfill('=') << "" << endl;
                cout << "Terima kasih telah menggunakan program ini." << endl << endl;
                cout << "NAMA : Zalfa Ghalib Hussein" << endl;
                cout << "NIM  : 124230097" << endl;
                cout << setw(60) << setfill('=') << "" << endl;

                // Simpan data ke file
                pembelian.saveToFile(file);
                pengembalian.saveToFile(file);
                file.close();
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);
    return 0;
}
