#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main() {
    int N;
    vector<string> lines;
    string fin, fout, char1;
    
    cout << "~: PALINDROME IN A TEXT :~\n\n";
    cout << "INPUT FILE NAME :  ";
    getline(cin, fin);
    cout << fin << endl;
    ifstream fptr2(fin);

    if (!fptr2)
    {
        cerr << "No such file found!" << endl;
        return -1;
    }
    cout << "OUTPUT FILE NAME : ";
    getline(cin, fout);
    ofstream fptr1(fout);

    while (getline(fptr2, char1)) {
        fptr1 << char1 << endl;
    }
    cout << "DONE !!";
    return 0;
}