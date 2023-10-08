#include<iostream>
#include<string>
using namespace std;

int str_Count(const string &str){
    int count = 0;
    int n = str.length();
    for(int j = 1; j < n; j++){
        if(str[j - 1] != ' ' && str[j] == ' ' ){
            count++;
        }
    }
    if(str[n - 1] != ' ' ){
        count++;
    }

   return count;
}


int main(){
    string str = " hi THIS is ARGHA . ";
    int n = str.length(), k = 0, str_C = str_Count(str);
    string word = "", WORD[str_C];

    if(str[0] != ' '){
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
        cout << WORD[i] << endl;
    }
    return 0;
}