#include<iostream>
#include<string>

using namespace std;

bool isPalindrome3(const string &str) {
    int left = 0;
    int right = str.length() - 1;
    cout<<left<<"\t"<<right<<endl;
    while (left < right) {
        // Ignore non-alphanumeric characters at the beginning
        while (left < right && !isalnum(str[left])) {
            left++;
            cout<< "HI1 " << left<<"\t"<<right<<endl;
        }
        
        // Ignore non-alphanumeric characters at the end
        while (left < right && !isalnum(str[right])) {
            right--;
            cout<< "HI2 " << left<<"\t"<<right<<endl;
        }

        // Compare lowercase characters
        if (tolower(str[left]) != tolower(str[right])) {
            cout << "HI3 " << endl;
            return false; // Not a palindrome
        }
        left++;
        right--;
    }

    return true; // It's a palindrome
}

bool isPalindrome2(const string &str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false; // Not a palindrome
        }
        left++;
        right--;
    }

    return true; // It's a palindrome
}

bool isPalindrome(const string &str) {
    int left = 0, right = str.length() - 1, flag_l = 0, flag_r = 0;
    while (left < right){
        while (left < right && !isalnum(str[left]) && flag_l == 0){
            left++;
        }
        flag_l = 1;
        while (left < right && !isalnum(str[right]) && flag_r == 0){
            right--;
        }
        flag_r = 1;
        if (tolower(str[left]) != tolower(str[right])) {
            return false; 
        }
        left++;
        right--;
    }
    return true;
}

int main(){
    cout<<isPalindrome("A.A");
    return 0;
}