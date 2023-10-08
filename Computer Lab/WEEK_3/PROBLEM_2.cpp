#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std; 

bool isPalindrome(const string &str) {
    int left = 0, right = str.length() - 1;
    while (left < right){
        if (tolower(str[left]) != tolower(str[right])) {
            return false; 
        }
        left++;
        right--;
    }
    return true;
}

void palindrome_vector(vector<string> &lines, const string &str, int N){
    int n = str.length();
    string word = "";
    vector<string> WORD;

    if(isalnum(str[0])){
        word = str[0];
    }

    for (int j = 1; j < n; j++)
    {
        if(isalnum(str[j])){
            word = word + str[j];
        }

        if(isalnum(str[j - 1]) && !isalnum(str[j])){
            WORD.push_back(word);
            word = "";
        }

    }

    if(isalnum(str[n - 1])){
        WORD.push_back(word);
    }

    for(int i = 0; i < WORD.size(); i++){
        if (isPalindrome(WORD[i]) && WORD[i].length() > N ) {
            lines.push_back(WORD[i]);
        }
    }
}

int main() {
    int N;
    vector<string> lines;
    string fin, fout, char1;
    
    cout << "~: PALINDROME IN A TEXT :~\n\n";
    cout << "INPUT FILE NAME :  ";
    getline(cin, fin);
    ifstream fptr2(fin);

    if (!fptr2)
    {
        cerr << "ERROR : No such file found!" << endl;
        return -1;
    }

    cout << "OUTPUT FILE NAME : ";
    getline(cin, fout);
    ofstream fptr1(fout);

    cout << "PALINDROME SIZE GREATER THAN : ";
    cin >> N;

    while (getline(fptr2, char1)) {
        palindrome_vector(lines, char1, N);
    }

    for (int i = lines.size() - 1; i >= 0; --i) {
        fptr1 << lines[i] << endl;
    }

    fptr1.close();
    fptr2.close();

    cout << "\nDONE !" << "\nPLEASE CHECK : " << fout;
    return 0;
}