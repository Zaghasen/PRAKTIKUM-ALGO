// OPERASI FILE MULTILINE STRING
#include "bits/stdc++.h"
using namespace std;

int main()
{
    ofstream ofs("File Multiline String.txt");
    if (ofs.is_open())
    {
        for (int i = 1; i <= 10; i++)
        {
            ofs << "Ini baris ke-" << i << endl;
        }
        ofs.close();
    }

    ifstream ifs("File Multiline String.txt");
    if (ifs.is_open())
    {
        string s;

        // baca per baris
        while (getline(ifs, s))
        {
            cout << s << endl;
        }
        // baca per kata
        while (ifs >> s)
        {
            cout << s << endl;
        }
        ifs.close();
    }
}