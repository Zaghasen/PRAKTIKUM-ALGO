#include <iostream>
#include <cctype>
#include <iomanip>

using namespace std;

// Definisi struktur Node
struct Node {
    char data;
    Node* next;
    Node* prev;
};

// Pointer kepala linked list
Node* head = nullptr;

// Fungsi untuk menyisipkan Node baru di awal Linked List
void insertNode(char data) {
    Node* newNode = new Node;
    newNode->data = toupper(data); // Mengubah huruf ke huruf besar
    newNode->next = head;
    newNode->prev = nullptr;
    if (head != nullptr)
        head->prev = newNode;
    head = newNode;
}

// Fungsi untuk menghapus Node dari Linked List
void deleteNode(char data) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr && current->data != toupper(data)) {
        current = current->next;
    }

    if (current != nullptr) {
        if (current == head) {
            head = current->next;
            if (head != nullptr)
                head->prev = nullptr;
        } else {
            current->prev->next = current->next;
            if (current->next != nullptr)
                current->next->prev = current->prev;
        }
        delete current;
    } else {
        cout << "Node with data '" << data << "' not found." << endl;
    }
}

// Fungsi untuk mencetak Linked List maju
void printForward() {
    cout << "Linked List (Maju): ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Fungsi untuk mencetak Linked List mundur
void printBackward() {
    cout << "Linked List (Mundur): ";
    Node* current = head;
    if (current != nullptr) {
        while (current->next != nullptr) {
            current = current->next;
        }
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->prev;
        }
    }
    cout << endl;
}

int main() {
    int choice;
    char data;

    do {
        cout << setw(60) << setfill('=') << "" << endl;
        cout << setw(40) << setfill(' ') << "Program Linked List" << endl;
        cout << setw(60) << setfill('=') << "" << endl;
        cout << "Menu:\n";
        cout << "1. Sisip Node\n";
        cout << "2. Hapus Node\n";
        cout << "3. Baca Maju\n";
        cout << "4. Baca Mundur\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan huruf (satu karakter): ";
                cin >> data;
                insertNode(data);
                break;
            case 2:
                cout << "Masukkan huruf yang akan dihapus: ";
                cin >> data;
                deleteNode(data);
                break;
            case 3:
                printForward();
                break;
            case 4:
                printBackward();
                break;
            case 5:
                cout << "Keluar dari program." << endl;
                cout << "Terima kasih telah menggunakan program ini." << endl << endl;
                cout << "NAMA : Zalfa Ghalib Hussein" << endl;
                cout << "NIM  : 124230097" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (choice != 5);

    // Dealokasi semua Node sebelum keluar dari program
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
