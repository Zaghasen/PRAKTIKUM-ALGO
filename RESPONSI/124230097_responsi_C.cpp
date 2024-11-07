#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Node {
    string nama;
    string car;
    int time;
    int jmlh;
    string spr;
    Node* next;

    Node(string n, string jk, int d, int jh, string s) : nama(n), car(jk), time(d), jmlh(jh), spr(s), next(NULL) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(NULL), rear(NULL) {}

    void enqueue(string nama, string car, int time, int jmlh, string spr) {
        Node* newNode = new Node(nama, car, time, jmlh, spr);
        if (rear == NULL) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    Node* dequeue() {
        if (front == NULL) {
            return NULL;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        return temp;
    }

    void display() {
        if (front == NULL) {
            cout << "KOSONG" << endl;
            return;
        }
        Node* current = front;
        while (current != NULL) {
			cout << setw(40) << setfill('=') << "" << endl;
            cout << "Nama : " << current->nama << endl;
            cout << "Jumlah Kendaraan : " << current->jmlh << endl;
            cout << "Jenis Kendaraan : " << current->car <<  endl;
            cout << "Waktu sewa (/jam) : " << current->time << endl;
            cout << "Memakai Jasa Supir? (Y/N) : " << current->spr << endl;
            current = current->next;
        }
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(NULL) {}

    void push(string nama, string car, int time, int jmlh, string spr) {
        Node* newNode = new Node(nama, car, time, jmlh, spr);
        newNode->next = top;
        top = newNode;
    }

    Node* pop() {
        if (top == NULL) {
            return NULL;
        }
        Node* temp = top;
        top = top->next;
        return temp;
    }

    void display() {
        if (top == NULL) {
            cout << "KOSONG" << endl;
            return;
        }
        Node* current = top;
        while (current != NULL) {
			cout << setw(40) << setfill('=') << "" << endl;
            cout << "Nama : " << current->nama << endl;
            cout << "Jumlah Kendaraan : " << current->jmlh << endl;
            cout << "Jenis Kendaraan : " << current->car << endl;
            cout << "Waktu sewa (/jam) : " << current->time << endl;
            cout << "Memakai Jasa Supir? (Y/N) : " << current->spr << endl;
            current = current->next;
        }
    }
};

void menu() {
    Queue rentalQueue;
    Stack returnStack;
    int choice;

    while (true) {
		cout << setw(60) << setfill('=') << "" << endl;
        cout << setw(40) << setfill(' ') << "SISTEM ANTREAN RENTAL MOBIL ZAGHASEN" << setfill(' ') << endl;
        cout << setw(60) << setfill('=') << "";
        cout << "\nMenu:" << endl;
        cout << "1. Input data penyewaan dan pengembalian" << endl;
        cout << "2. Output data pelanggan yang mengantri penyewaan" << endl;
        cout << "3. Output data pelanggan yang mengantri pengembalian" << endl;
        cout << "4. Menghapus data pelanggan yang mengantri" << endl;
        cout << "5. Keluar dari Program" << endl;
        cout << "Pilih menu: ";
        cin >> choice;

        if (choice == 1) {
            int sub_choice;
            cout << setw(40) << setfill('=') << "" << endl;
            cout << "1. Antrian penyewaan\n2. Antrian pengembalian\nPilih: ";
            cin >> sub_choice;
            cin.ignore();
            cout << setw(40) << setfill('=') << "" << endl;
            string nama, car, spr;
            int time, jmlh;
            cout << setw(40) << setfill('=') << "" << endl;
            cout << "Nama pelanggan: ";
            getline(cin, nama);
            cout << "Jumlah Kendaraan : ";
            cin >> jmlh;
            cout << "Jenis Kendaraan";
            cout << "\n- Avanza";
            cout << "\n- Xenia";
            cout << "\n- Ferari";
            cout << "\n- Mazda";
            cout << "\n- PickUp";
            cout << "\nPilihan : ";
            cin >> car;
            cout << "Waktu penyewaan (/jam) : ";
            cin >> time;
            cout << "Memakai jasa supir? (Y/N) : ";
            cin >> spr;
            cout << setw(40) << setfill('=') << "" << endl;

            if (sub_choice == 1) {
                rentalQueue.enqueue(nama, car, time, jmlh, spr);
            } else if (sub_choice == 2) {
                returnStack.push(nama, car, time, jmlh, spr);
            } else {
                cout << "Pilihan tidak valid." << endl;
            }

        } else if (choice == 2) {
			cout << setw(40) << setfill('=') << "" << endl;
            cout << "Antrian penyewaan:" << endl;
            rentalQueue.display();
            cout << setw(40) << setfill('=') << "" << endl;

        } else if (choice == 3) {
			cout << setw(40) << setfill('=') << "" << endl;
            cout << "Antrian pengembalian:" << endl;
            returnStack.display();
            cout << setw(40) << setfill('=') << "" << endl;

        } else if (choice == 4) {
            int sub_choice;
            cout << setw(40) << setfill('=') << "" << endl;
            cout << "1. Antrian penyewaan\n2. Antrian pengembalian\nPilih: ";
            cin >> sub_choice;
            cout << setw(40) << setfill('=') << "" << endl;

            if (sub_choice == 1) {
                Node* hapusData = rentalQueue.dequeue();
                if (hapusData != NULL) {
					cout << setw(40) << setfill('=') << "" << endl;
                    cout << "Data yang dihapus : " << endl;
                    cout << "Nama : " << hapusData->nama << endl;
                    cout << "Jumlah Kendaraan : " << hapusData->jmlh << endl;
                    cout << "Jenis Kendaraan : " << hapusData->car << endl;
                    cout << "Waktu Sewa (/jam) : " << hapusData->time << endl;
                    cout << "Memakai Jasa Supir? (Y/N) : " << hapusData->spr << endl;
                    delete hapusData;
                } else {
                    cout << "Antrian penyewaan kosong." << endl;
                }
            } else if (sub_choice == 2) {
                Node* hapusData = returnStack.pop();
                if (hapusData != NULL) {
					cout << setw(40) << setfill('=') << "" << endl;
                    cout << "Data yang dihapus : " << endl;
                    cout << "Nama : " << hapusData->nama << endl;
                    cout << "Jumlah Kendaraan : " << hapusData->jmlh << endl;
                    cout << "Jenis Kendaraan : " << hapusData->car << endl;
                    cout << "Waktu Sewa (/jam) : " << hapusData->time << endl;
                    cout << "Memakai Jasa Supir? (Y/N) : " << hapusData->spr << endl;
                    delete hapusData;
                } else {
                    cout << "Antrian pengembalian kosong." << endl;
                }
            } else {
                cout << "Pilihan tidak valid." << endl;
            }

        } else if (choice == 5) {
				cout << setw(50) << setfill('=') << "" << endl;
                cout << "Terima kasih telah menggunakan program ini." << endl << endl;
                cout << "NAMA : Zalfa Ghalib Hussein" << endl;
                cout << "NIM  : 124230097" << endl;
                cout << setw(50) << setfill('=') << "" << endl;
            break;

        } else {
            cout << "Pilihan tidak valid. Coba lagi." << endl;
        }
    }
}

int main() {
    menu();
    return 0;
}
