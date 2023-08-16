#include <iostream>

using namespace std;

int HCF(int N1, int N2) {
    while (N2 != 0) {
        int temp = N2;
        N2 = N1 % N2;
        N1 = temp;
    }
    return N1;
}

int main() {
    int N1, N2;

    cout << "Enter the first number: ";
    cin >> N1;

    cout << "Enter the second number: ";
    cin >> N2;

    int hcf = HCF(N1, N2);
    cout << "HCF of " << N1 << " and " << N2 << " is: " << hcf << endl;

    return 0;
}
