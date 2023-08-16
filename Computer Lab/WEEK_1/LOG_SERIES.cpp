#include <iostream>
#include <cmath>

double log_series_expansion(double x, int terms) {
    double result = 0.0;
    double power_x = x;

    for (int n = 1; n <= terms; n++) {
        if (n % 2 == 1) {
            result += power_x / n;
        } else {
            result -= power_x / n;
        }
        power_x *= x;
    }

    return result;
}

int main() {
    double x;
    int terms;

    std::cout << "Enter the value of x: ";
    std::cin >> x;

    std::cout << "Enter the number of terms to use in the series expansion: ";
    std::cin >> terms;

    double expansion_result = log_series_expansion(x, terms);

    std::cout << "log(1 + " << x << ") = " << expansion_result << std::endl;

    return 0;
}
