#include <iostream>

using namespace std;

double myAbs(double num) {
    return (num >= 0) ? num : -num;
}

//Using the newton Raphson method
double squareRoot(double num, double epsilon) {
    double x = num;
    while (myAbs(x * x - num) > epsilon) {
        x = 0.5 * (x + num / x);
    }
    return x;
}

int main() {
    double num, epsilon;
    cout << "Enter a number to find its square root: ";
    cin >> num;

    if (num < 0) {
        cout << "Square root of a negative number is not real." << endl;
    } else {
        cout << "Enter the desired epsilon value: ";
        cin >> epsilon;

        double result = squareRoot(num, epsilon);
        cout << "Square root of " << num << " is approximately " << result << endl;
    }

    return 0;
}
