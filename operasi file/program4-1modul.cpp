// menciptakan & mengisi file dengan data karakter dari keyboard
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define CTRL_Z 26
using namespace std;
int main()
{
    FILE *pf;                                       // pointer ke FILE
    char kar;
    if((pf = fopen("COBA.TXT", "w")) == NULL)       // ciptakan FILE
    {
        cout << "file tak dapat diciptakan! \r\n";  // tulis ke layar
        exit(1);                                    // selesai
    }
    while((kar = getchar()) != CTRL_Z)              // baca kar dari fle
    fputc(kar, pf);                                 // tulis ke file
    fclose(pf);                                     // tutup file
}