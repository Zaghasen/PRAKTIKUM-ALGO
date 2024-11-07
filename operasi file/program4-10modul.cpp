// membaca data yang diformat dalam file, dengan fscan()
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    struct 
    {
    int x, y;
    } koordinat;

FILE *pkoord;
char kar; // menyinpan \n dari file
int kode; // memegang keluaran fungsi fscan()

if((pkoord = fopen("koordinat.txt", "rt")) == NULL)
{
    cout << "File tidak dapat dibuka !!";
    exit(1);
}

while((kode = fscanf(pkoord, "5%d5%d%c", &koordinat.x, &koordinat.y, &kar))!= EOF)
{
    if(kode != 3)
    {
        cout << "Program dihentikan.\r\n";
        cout << "Sebab format data dalam file salah!\r\n";
        exit(1);
    }
    cout << koordinat.x << " " << koordinat.y << "\r\n";
}

fclose(pkoord);
getchar();
}