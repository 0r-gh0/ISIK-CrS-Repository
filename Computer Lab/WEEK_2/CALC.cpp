#include <iostream>
#include <complex>  // Include the complex number library

using namespace std;

int main() {

while (true)
{
        complex<double> num1, num2, result;
        char operation;

        cout << "Enter the first number : ";
        cin >> num1;

        cout << "Enter operation (+, -, *, /): ";
        cin >> operation;

        cout << "Enter the second number : ";
        cin >> num2;

    switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                if (num2.real() != 0 || num2.imag() != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                    return 1;  // Exit with an error code
                }
                break;
            default:
                cout << "Invalid operation." << endl;
                return 1;  // Exit with an error code
        }

        cout << "Result: " << result.real() << " + " << result.imag() << "i" << endl;

    int i;
    cout << "(Press 0/1) Please select to continue : ";
    cin >> i;
    if(i == 0){
        break;
    }

}

    return 0;  // Exit without errors

}
