#include <iostream>
#include <iomanip>
#include <cctype>

using namespace std;

// Definisi struktur Node untuk queue
struct Node {
    char data;
    Node* next;
};

// Definisi kelas Queue
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Fungsi untuk menambahkan elemen ke dalam queue (enqueue)
    void enqueue(char data) {
        data = toupper(data);  // Convert to uppercase
        Node* newNode = new Node{data, nullptr};
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Fungsi untuk menghapus elemen dari queue (dequeue)
    void dequeue(int count) {
        while (count-- > 0 && front != nullptr) {
            Node* temp = front;
            front = front->next;
            if (front == nullptr) {
                rear = nullptr;
            }
            delete temp;
        }
    }

    // Fungsi untuk mencetak elemen-elemen dalam queue
    void printQueue() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Destruktor untuk membersihkan memori
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
        cout << setw(60) << setfill('=')<<""<<endl;
        cout << setw(40) << setfill(' ')<< "Program Stack & Queue"<< setfill(' ')<< endl;
        cout << setw(60) << setfill('=')<<""<<endl;
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
                    cout << "Masukkan karakter: ";
                    cin >> ws >> data;  // Menggunakan ws untuk mengabaikan whitespace
                    queue.enqueue(data);
                }
                break;

            case 2:
                cout << "Masukkan banyaknya node yang ingin dihapus: ";
                cin >> count;
                queue.dequeue(count);
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
