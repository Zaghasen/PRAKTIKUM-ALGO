// program menukar isi string yang ditunjuk pointer

#include <iostream>
#define panjang 20
using namespace std;

char *nama1 = "Zalfa";
char *nama2 = "Ghalib";
char *nama3 = "Hussein";

int main() {
	char *namax;
	cout << "semula :" << endl;
	cout << "nama1 -> " << nama1 << endl;
	cout << "nama2 -> " << nama2 << endl;
	cout << "nama3 -> " << nama3 << endl;

    // penukaran string yang ditunjuk oleh pointer nama1 nama2 nama3
    namax = nama1;
    nama1 = nama2;
    nama2 = nama3;
    nama3 = namax;

    cout << "kini :" << endl;
    cout << "nama1 -> " << nama1 << endl;
    cout << "nama2 -> " << nama2 << endl;
    cout << "nama3 -> " << nama3 << endl;

return 0;
}
