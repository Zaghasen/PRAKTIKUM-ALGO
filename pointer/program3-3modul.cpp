// contoh pointer yang menunjuk array
#include <iostream>
using namespace std;

int main()
{
	static int tgl_lahir[] = {11, 11, 2004};
	int  *ptgl;
	ptgl = tgl_lahir; // ptgl berisi alamat array
	
	cout << "nilai yang ditunjuk oleh ptgl = " << *ptgl << endl;
	cout << "nilai dari tgl_lahir[0] = " << tgl_lahir[0] << endl;
}
