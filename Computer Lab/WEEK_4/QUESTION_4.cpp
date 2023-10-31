#include <iostream>
#include <random>
using namespace std;

void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int N;
    cout << "Enter the size of Array (Greater than 1024): ";
    cin >> N;

    if (N <= 1024) {
        cout << "Array size must be greater than 1024." << endl;
        return 1;
    }

    int* ARR = new int[N];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(0, N - 1);

    for (int i = 0; i < N; i++) {
        ARR[i] = dist(gen);
    }

    cout << "ARRAY CREATED : \n";
    display(ARR, N);

    cout << "\nAFTER SORTING : \n";
    quickSort(ARR, 0, N - 1);
    display(ARR, N);

    delete[] ARR;
    return 0;
}
