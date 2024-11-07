#include <iostream>
#include <malloc.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int *p, *q, *r;
	int n = 10;
	p = (int *)malloc(sizeof(int));
	q = (int *)malloc(sizeof(int));
	
	p = &n;
	*q = 120;
	r = p;
	
	cout << "isi info pointer : \n";
	cout << "*p = " << *p << endl;
	cout << "*q = " << *q << endl;
	cout << "*r = " << *r << endl;
	
	cout << "\nAlamat register pointer : \n";
	cout << "p = " << p << endl;
	cout << "q = " << q << endl;
	cout << "r = " << r << endl;
	
	n = *q;
	p = q;
	
	cout << "\nKondisi akhir isi pointer : \n";
	cout << "n = " << n << endl;
	cout << "*p = " << *p << endl;
	cout << "*q = " << *q << endl;
	cout << "*r = " << *r << endl;
}
