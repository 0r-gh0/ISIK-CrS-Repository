#include <iostream>

using namespace std;

double Abso(double num) {
    return (num >= 0) ? num : -num;
}

double sine(double x, double tolerance) {
    double result = 0.0;
    double term = x;
    int n = 1;

    while (Abso(term) >= tolerance) {
        result += term;
        term = -term * (x * x) / ((2 * n) * (2 * n + 1));
        n++;
    }

    return result;
}

int main() {
    double angle, tolerance;

    cout << "Enter the angle in radians: ";
    cin >> angle;

    cout << "Enter the tolerance (in 1e-6): ";
    cin >> tolerance;

    double sineValue = sine(angle, tolerance);

    cout << "sin(" << angle << ") = " << sineValue << endl;

    return 0;
}
