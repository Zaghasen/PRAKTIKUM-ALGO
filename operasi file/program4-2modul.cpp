// menciptakan & mengisi file dengan data karakter dari keyboard
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{
    FILE *pf;                                   // pointer ke FILE
    char kar;
    if((pf = fopen("COBA.TXT", "r")) == NULL)   // buka FILE
    {
        cout << "file tak dapat dibuka! \r\n";  // tulis ke layar
        exit(1);                                // selesai
    }
    while((kar = getchar()) != EOF)                // baca kar dari fle
    cout << kar;                                // tampilkan ke file
    fclose(pf);                                 // tutup file
    getchar();
}