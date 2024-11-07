// OPERASI FILE POSISI STRING
#include "bits/stdc++.h"
using namespace std;
 
int main() {
    string s1 = "Halo Dunia!";
    string s2;
    
    ofstream ofs("File String.txt");
    
    if (ofs.is_open()) {
        ofs << s1; 
        
        ofs.close();
    }
 
    ifstream ifs("File String.txt");
    
    if (ifs.is_open()) {
        ifs >> s2;
        
        cout << s2 << endl;
 
        // mengatur posisi stream
        ifs.seekg(0,ios::beg);
        
        /*
            ios::beg -> awal
            ios::cur -> sekarang
            ios::end -> akhir
        */
        
        getline(ifs, s2);
        cout << s2 << endl;
        
        ifs.close();
    }
}