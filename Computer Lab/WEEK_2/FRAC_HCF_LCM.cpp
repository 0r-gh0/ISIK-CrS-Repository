#include <iostream>

using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int findLCM(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = lcm(result, arr[i]);
    }
    return result;
}

int findHCF(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
    }
    return result;
}

int main() {

int NUM[5], DEN[5];

    Fraction fraction[5];

    cout << "Enter the first numerator: ";
    cin >> fraction[0].numerator;

    cout << "Enter the first denominator: ";
    cin >> fraction[0].denominator;

    cout << endl << "Enter the second numerator: ";
    cin >> fraction[1].numerator;

    cout << "Enter the second denominator: ";
    cin >> fraction[1].denominator;

    cout << endl << "Enter the third numerator: ";
    cin >> fraction[2].numerator;

    cout << "Enter the third denominator: ";
    cin >> fraction[2].denominator;

    cout << endl << "Enter the fourth numerator: ";
    cin >> fraction[3].numerator;

    cout << "Enter the fourth denominator: ";
    cin >> fraction[3].denominator;

    cout << endl << "Enter the fifth numerator: ";
    cin >> fraction[4].numerator;

    cout << "Enter the fifth denominator: ";
    cin >> fraction[4].denominator;
    
    for(int i = 0; i < 5; i++){
        NUM[i] = fraction[i].numerator;
        DEN[i] = fraction[i].denominator;
    }

    int lcmResult = findLCM(NUM, 5);
    int hcfResult = findHCF(DEN, 5);
    
    cout << endl << "LCM of the five numbers is: " << lcmResult << endl;
    cout << "HCF of the five numbers is: " << hcfResult << endl;

    cout << endl << "LCM OF 5 FRACTIONS ARE : " << lcmResult << "/" <<  hcfResult;
    
    return 0;
}
