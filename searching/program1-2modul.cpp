// SeqSearch_BelumUrut_Sentinel (cara 1)
/* 
 diasumsikan array[0..10] sudah ada dan indeks ke 0..9 telah berisi data yang belum urut, 
 nilai yang dicari adalah nilaiCari dan hanya ada satu, nilaiCari diletakkan di index ke-10
 */
 
 #include <iostream>
 using namespace std;
 
 int main()
 {
	 int x[11] = {20, 50, 10, 30, 90, 60, 70, 80, 40, 100};
	 int i, nilaiCari; 

	 cout << "Nilai yang diicari = "; 
	 cin >> nilaiCari;
	 
	 x[10] = nilaiCari;
	 i=0;
	 while(x[i] != nilaiCari)
	 i = i + 1;
	 if(i > 9)
	    cout << "tidak ada " << nilaiCari << " dalam array" << endl;
	 else
	    cout << nilaiCari << " ditemukan dalam array pada index ke-" << i << endl;
 }
