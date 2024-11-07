// SeqSearch_BelumUrut_Sentinel (cara 2)
/* 
 diasumsikan array[0..10] sudah ada dan indeks ke 0..9 telah berisi data yang belum urut, 
 nilai yang dicari adalah y dan hanya ada satu, y diletakkan di index ke-10
 */
 
 #include <iostream>
 using namespace std;
 
 int main()
 {
	int x[10] = {20, 50, 10, 30, 90, 60, 70, 80, 40, 100};
	 bool found;
	 int i, nilaiCari;
	 
	 cout << "nilai yang dicari = "; 
	 cin >>  nilaiCari;
	 
	 x[10] = nilaiCari;
	 found = false;
	 i=0;
	 while(!found)
	 {
		 if(x[i] == nilaiCari) found = true;
		 else i = i + 1;
	 }
	 if(i == 10)
	    cout << "tidak ada" << nilaiCari << " dalam array" << endl;
	 else
	    cout << nilaiCari << " ditemukan dalam array pada index ke-" << i << endl;
 }
