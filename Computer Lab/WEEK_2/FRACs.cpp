#include <iostream>

using namespace std;

struct Fraction {
    int numerator;
    int denominator;
};

bool compareFractions(Fraction frac1, Fraction frac2) { 
    if( (frac1.numerator * frac2.denominator) > (frac2.numerator * frac1.denominator) ){
        return true;
    }
    else 
        return false;
}


int main() {
    Fraction fraction1, fraction2, fraction3;

    cout << "Enter the first numerator: ";
    cin >> fraction1.numerator;

    cout << "Enter the first denominator: ";
    cin >> fraction1.denominator;

    cout << endl << "Enter the second numerator: ";
    cin >> fraction2.numerator;

    cout << "Enter the second denominator: ";
    cin >> fraction2.denominator;

    cout << endl << "Enter the third numerator: ";
    cin >> fraction3.numerator;

    cout << "Enter the third denominator: ";
    cin >> fraction3.denominator;


    if (fraction1.denominator == 0 || fraction2.denominator == 0 || fraction3.denominator == 0) {
        cout << "Denominator cannot be zero." << endl;
    } else {
        bool firstIsGreater = compareFractions(fraction1, fraction2);

        if(firstIsGreater == true){
            firstIsGreater = compareFractions(fraction1, fraction3);
            if (firstIsGreater == true)
            {
                cout << "The largest fraction is : " << fraction1.numerator << "/" << fraction1.denominator;
            }
            else{
                cout << "The largest fraction is : " << fraction2.numerator << "/" << fraction2.denominator;
            }
        }
        else{
            firstIsGreater = compareFractions(fraction2, fraction3);
            if (firstIsGreater == true)
            {
                cout << "The largest fraction is : " << fraction2.numerator << "/" << fraction2.denominator;
            }
            else{
                cout << "The largest fraction is : " << fraction3.numerator << "/" << fraction3.denominator;
            }
        }
    }
    return 0;
}
