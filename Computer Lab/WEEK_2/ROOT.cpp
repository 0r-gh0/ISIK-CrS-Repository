#include <iostream>
#include <cmath>
#include <complex> 

using namespace std;

struct QuadraticRoots {
    complex<double> root1;
    complex<double> root2;
};

QuadraticRoots calculateQuadraticRoots(double a, double b, double c) {
    QuadraticRoots roots;
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        roots.root1 = (-b + sqrt(discriminant)) / (2 * a);
        roots.root2 = (-b - sqrt(discriminant)) / (2 * a);
    } else if (discriminant == 0) {
        roots.root1 = roots.root2 = -b / (2 * a);
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        roots.root1 = complex<double>(realPart, imaginaryPart);
        roots.root2 = complex<double>(realPart, -imaginaryPart);
    }

    return roots;
}

int main() {
    double a, b, c;
    cout << "Enter the coefficients (a, b, c) of the quadratic equation: ";
    cin >> a >> b >> c;

    QuadraticRoots roots = calculateQuadraticRoots(a, b, c);

    if (roots.root1.imag() == 0) {
        cout << "Root 1: " << roots.root1.real() << endl;
        cout << "Root 2: " << roots.root2.real() << endl;
    } else {
        //cout << "Root 1: " << roots.root1 << endl;
        cout << "Root 1: " << roots.root1.real() << " + " << roots.root1.imag() << "i" << endl;
        cout << "Root 2: " << roots.root2.real() << " + " << roots.root2.imag() << "i" << endl;
        //cout << "Root 2: " << roots.root2 << endl;
    }

    return 0;
}
