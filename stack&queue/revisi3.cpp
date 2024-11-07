#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

struct Node {
    char data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Fungsi untuk menambahkan elemen ke dalam queue (enqueue)
    void enqueue(char data) {
        data = toupper(data);
        Node* newNode = new Node{data, nullptr};
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Fungsi untuk menghapus node tertentu dari queue (dequeue)
    void dequeueSpecific(char data) {
        data = toupper(data);
        if (front == nullptr) {
            cout << "Queue kosong." << endl;
            return;
        }

        Node* current = front;
        Node* previous = nullptr;

        while (current != nullptr && current->data != data) {
            previous = current;
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Node dengan data '" << data << "' tidak ditemukan." << endl;
            return;
        }

        if (previous == nullptr) {
            front = current->next;
            if (front == nullptr) {
                rear = nullptr;
            }
        } else {
            previous->next = current->next;
            if (current->next == nullptr) {
                rear = previous;
            }
        }

        delete current;
    }

    // Fungsi untuk mencetak elemen-elemen dalam queue
    void printQueue() {
        if (front == nullptr) {
            cout << "Queue kosong." << endl;
            return;
        }

        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~Queue() {
        while (front != nullptr) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

// Fungsi utama
int main() {
    Queue queue;
    int choice, count;
    char data;

    do {
        cout << setw(60) << setfill('=') << "" << endl;
        cout << setw(40) << setfill(' ') << "Program Queue" << setfill(' ') << endl;
        cout << setw(60) << setfill('=') << "" << endl;
        cout << "Menu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Cetak\n";
        cout << "4. Keluar\n";
        cout << "Pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan banyaknya node yang ingin ditambahkan: ";
                cin >> count;
                for (int i = 0; i < count; i++) {
                    cout << "Masukkan karakter (satu karakter): ";
                    cin >> ws >> data;
                    queue.enqueue(data);
                }
                break;

            case 2:
                cout << "Masukkan banyaknya node yang ingin dihapus: ";
                cin >> count;
                for (int i = 0; i < count; i++) {
                    cout << "Masukkan karakter dari node yang ingin dihapus (satu karakter): ";
                    cin >> ws >> data;
                    queue.dequeueSpecific(data);
                }
                break;

            case 3:
                cout << "Isi queue: ";
                queue.printQueue();
                break;

            case 4:
                cout << "Keluar dari program." << endl;
                cout << "Terima kasih telah menggunakan program ini." << endl << endl;
                cout << "NAMA : Zalfa Ghalib Hussein" << endl;
                cout << "NIM  : 124230097" << endl;
                break;

            default:
                cout << "Pilihan tidak valid!\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
