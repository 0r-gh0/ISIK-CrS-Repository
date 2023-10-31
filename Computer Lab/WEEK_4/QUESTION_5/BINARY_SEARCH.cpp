#include <iostream>
#include <random>
#include "QUICK_SORT.h"
using namespace std;

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid; 
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int N;

    while(true){
        cout << "ENTER THE SIZE OF ARRAY (Greater than 1024) : ";
        cin >> N;
        if (N <= 10) {
            cout << "Array size must be greater than 1024 !! (PRESS AGAIN)\n" << endl;
        } else{break;}
    }

    int* ARR = new int[N];
    genArray(ARR,N);

    cout << "ARRAY CREATED : \n";
    display(ARR, N);

    cout << "\nAFTER SORTING : \n";
    quickSort(ARR, 0, N - 1);
    display(ARR, N);

    int key;
    cout << "ENTER THE KEY : ";
    cin >> key;

    int result = binarySearch(ARR, N, key);

    if (result != -1)
        cout << "\nELEMENT FOUND AT POSITION :  " << result << endl;
    else
        cout << "\nELEMENT NOT FOUND !" << endl;

    delete[] ARR;
    return 0;
}