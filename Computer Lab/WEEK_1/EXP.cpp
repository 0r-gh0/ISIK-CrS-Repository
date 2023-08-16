#include <iostream>
#include <cmath>

using namespace std;
 
double customAbs(double num) {
    return (num < 0) ? -num : num;
}

double calculateExponential(double x, double epsilon) {
    double result = 1.0; // Initialize the result as 1 to account for the first term (n = 0)
    double term = 1.0;
    int n = 1;

    while (customAbs(term) > epsilon) {
        term *= x / n; // Calculate the next term based on the previous term
        result += term; // Add the current term to the result
        n++;
    }

    return result;
}

int main() {
    double x;
    double epsilon;

    cout << "Enter the value of x: ";
    cin >> x;

    cout << "Enter the epsilon value for approximation: ";
    cin >> epsilon;

    double result = calculateExponential(x, epsilon);
    double actual_result = exp(x); // Using the cmath library's exponential function for comparison

    cout << "Approximated e^" << x << " with epsilon " << epsilon << ": " << result << endl;
    cout << "Actual e^" << x << " using cmath library: " << actual_result << endl;

    return 0;
}
