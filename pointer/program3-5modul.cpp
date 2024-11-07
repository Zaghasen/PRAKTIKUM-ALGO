// contoh pointer yang menunjuk array
#include <iostream>
using namespace std;

int main()
{
	static int tgl_lahir[] = {11, 11, 2004};
	int i;
	int  *ptgl;
	
	ptgl = tgl_lahir; // ptgl berisi alamat array
	
	for(i=0; i<3; i++)
	cout << *(ptgl + i) << " ";
	cout << endl;
}
