// SeqSearch_BelumUrut_nonSentinel
// diasumsikan array x suda ada dan berisi data yang belum urut nilai yang dicari adalah nilaiCari dan hanya ada satu

#include <iostream>
using namespace std;
 int main ()
 {
	 int x[10] = {20, 50, 10, 30, 90, 60, 70, 80, 40, 100};
	 bool found;
	 int i, nilaiCari;
	 
	 cout << "nilai yang dicari = "; 
	 cin >>  nilaiCari;
	 
	 found = false;
	 i = 0;
	 while((i < 10) & (!found))
	 {
		 if(x[i] == nilaiCari)
		 found = true;
		 else
		 i = i + 1;
	 }
	 
	 if(found)
	    cout << nilaiCari << " ditemukan pada index array ke- " << i << endl;
	 else
	    cout << nilaiCari << " tidak ada dalam array tersebut " << endl;
 }

