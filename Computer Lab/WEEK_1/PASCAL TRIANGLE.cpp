#include <iostream>
using namespace std;

void pTri(int rows){
    for (int i = 0; i < rows; i++) {

        for (int space = 0; space < (rows - i - 1); space++)
            cout << " ";

        int number = 1;

        for (int j = 0; j <= i; j++) {
            cout << number << " ";
            number = number * (i - j) / (j + 1);
        }
        cout << endl;
    }
}

int main() {
    int r;

    cout << " Please enter the of rows for Pascal's triangle: ";
    cin >> r;

    pTri(r);
    return 0;
}
