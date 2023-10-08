#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std; 

// int str_Count(const string &str){
//     int count = 0;
//     int n = str.length();
//     for(int j = 1; j < n; j++){
//         if(str[j - 1] != ' ' && str[j] == ' '){
//             count++;
//         }
//     }
//     if(str[n - 1] != ' '){
//         count++;
//     }
//     return count;
// }

bool isPalindrome2(const string &str) {
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

// bool isPalindrome2(const string &str) {
//     int left = 0, right = str.length() - 1, flag_l = 0, flag_r = 0;
//     while (left < right){
//         while (left < right && !isalnum(str[left]) && flag_l == 0){
//             left++;
//         }
//         flag_l = 1;
//         while (left < right && !isalnum(str[right]) && flag_r == 0){
//             right--;
//         }
//         flag_r = 1;
//         int l = left, r = right;
//         if (tolower(str[left]) != tolower(str[right])) {
//             return false; 
//         }
//         left++;
//         right--;
//     }
//     return true;
// }


void palindrome_vector4(vector<string> &lines, const string &str, int N){
    int n = str.length(), k = 0, flag = 0;
    string word = "";
    vector<string> WORD;

    if(isalnum(str[0])){
        word = str[0];
        cout << flag << word << endl;
    }

    for (int j = 1; j < n; j++)
    {
        // if(str[j - 1] != ' ' && str[j] != ' ' && flag == 1){
        //     word = word + str[j];
        //     cout << flag << word << endl;
        // }

        if(isalnum(str[j])){
            word = word + str[j];
            cout << flag << word << endl;
        }

        if(isalnum(str[j - 1]) && !isalnum(str[j])){
            WORD.push_back(word);
            cout << flag << word << endl;
            k++;
            word = "";
        }

        // if(str[j - 1] == ' ' && str[j] != ' '  && flag == 1){
        //     word = str[j];
        //     cout << flag << word << endl;
        // }
    }

    if(isalnum(str[n - 1])){
        WORD.push_back(word);
        cout << flag << word << endl;
        k++;
    }

    for(int i = 0; i < WORD.size(); i++){
        if (isPalindrome2(WORD[i]) && WORD[i].length() > N ) {
            lines.push_back(WORD[i]);
        }
    }
}

// void palindrome_vector3(vector<string> &lines, const string &str, int N){
//     int n = str.length(), k = 0, flag = 0;
//     string word = "";
//     vector<string> WORD;

//     if(str[0] != ' ' && isalnum(str[0])){
//         word = str[0];
//         flag = 1;
//         cout << flag << word << endl;
//     }

//     for (int j = 1; j < n; j++)
//     {
//         if (isalnum(str[j])){flag = 1;}
//         else{flag = 0;}
        
//         if(str[j - 1] != ' ' && str[j] != ' ' && flag == 1){
//             word = word + str[j];
//             cout << flag << word << endl;
//         }

//         if(str[j - 1] != ' ' && str[j] == ' '){
//             WORD.push_back(word);
//             cout << flag << word << endl;
//             k++;
//             word = "";
//         }

//         if(str[j - 1] == ' ' && str[j] != ' '  && flag == 1){
//             word = str[j];
//             cout << flag << word << endl;
//         }
//     }

//     if(str[n - 1] != ' '){
//         WORD.push_back(word);
//         cout << flag << word << endl;
//         k++;
//     }

//     for(int i = 0; i < WORD.size(); i++){
//         if (isPalindrome(WORD[i]) && WORD[i].length() > N ) {
//             lines.push_back(WORD[i]);
//         }
//     }
// }



/*
void palindrome_vector2(vector<string> &lines, const string &str, int N){
    int n = str.length(), k = 0, str_C = str_Count(str), flag = 0;
    string word = "", WORD[str_C];

    if(isalnum(str[0])){
        word = str[0];
        flag = 1;
        cout << flag << word << endl;
    }

    for (int j = 1; j < n; j++)
    {
        if (isalnum(str[j])){flag = 1;}
        else{flag = 0;}
        
        if(str[j - 1] != ' ' && str[j] != ' ' && flag == 1){
            word = word + str[j];
            cout << flag << word << endl;
        }

        if(str[j - 1] != ' ' && str[j] == ' '){
            WORD[k] = word;
            cout << flag << word << endl;
            k++;
            word = "";
        }

        if(str[j - 1] == ' ' && str[j] != ' '  && flag == 1){
            word = str[j];
            cout << flag << word << endl;
        }
    }

    if(str[n - 1] != ' '){
        WORD[k] = word;
        cout << flag << word << endl;
        k++;
    }

    for(int i = 0; i < k; i++){
        if (isPalindrome(WORD[i]) && WORD[i].length() > N ) {
            lines.push_back(WORD[i]);
        }
    }
}
*/


// void palindrome_vector1(vector<string> &lines, const string &str, int N){
//     int n = str.length(), k = 0, str_C = str_Count(str), flag = 0;
//     string word = "", WORD[str_C];

//     if(str[0] != ' ' && isalnum(str[0])){
//         word = str[0];
//         flag = 1;
//         cout << flag << word << endl;
//     }

//     for (int j = 1; j < n; j++)
//     {
//         if (isalnum(str[j])){flag = 1;}
//         else{flag = 0;}
        
//         if(str[j - 1] != ' ' && str[j] != ' ' && flag == 1){
//             word = word + str[j];
//             cout << flag << word << endl;
//         }

//         if(str[j - 1] != ' ' && str[j] == ' '){
//             WORD[k] = word;
//             cout << flag << word << endl;
//             k++;
//             word = "";
//         }

//         if(str[j - 1] == ' ' && str[j] != ' '  && flag == 1){
//             word = str[j];
//             cout << flag << word << endl;
//         }
//     }

//     if(str[n - 1] != ' '){
//         WORD[k] = word;
//         cout << flag << word << endl;
//         k++;
//     }

//     for(int i = 0; i < k; i++){
//         if (isPalindrome(WORD[i]) && WORD[i].length() > N ) {
//             lines.push_back(WORD[i]);
//         }
//     }
// }

/*
void palindrome_vector0(vector<string> &lines, const string &str, int N){
    int n = str.length(), k = 0, str_C = str_Count(str);
    string word = "", WORD[str_C];

    if(str[0] != ' ' ){
        word = str[0];
    }

    for (int j = 1; j < n; j++)
    {
        if(str[j - 1] != ' ' && str[j] != ' '){
            word = word + str[j];
        }

        if(str[j - 1] != ' ' && str[j] == ' '){
            WORD[k] = word;
            k++;
            word = "";
        }

        if(str[j - 1] == ' ' && str[j] != ' '){
            word = str[j];
        }
    }

    if(str[n - 1] != ' '){
        WORD[k] = word;
        k++;
    }

    for(int i = 0; i < k; i++){
        if (isPalindrome(WORD[i]) && WORD[i].length() > N ) {
            lines.push_back(WORD[i]);
        }
    }
}
*/


int main() {
    int N;
    vector<string> lines;
    string fin, fout, char1;
    
    cout << "~: PALINDROME IN A TEXT :~\n\n";
    cout << "INPUT FILE NAME :  ";
    cin >> fin;
    ifstream fptr2(fin);

    if (!fptr2)
    {
        cerr << "No such file found!" << endl;
        return -1;
    }

    cout << "OUTPUT FILE NAME : ";
    cin >> fout;
    ofstream fptr1(fout);

    cout << "PALINDROME SIZE GREATER THAN : ";
    cin >> N;

    while (getline(fptr2, char1)) {
        palindrome_vector4(lines, char1, N);
    }

    for (int i = lines.size() - 1; i >= 0; --i) {
        fptr1 << lines[i] << endl;
    }

    fptr1.close();
    fptr2.close();

    cout << "\nDONE !" << "\nPLEASE CHECK : " << fout;
    return 0;
}