#include <iostream>
#include <cmath>
using namespace std;

int co_i(int k){
    return ((-1 + sqrt(8*k + 1))/2);
}

int co_j(int k){
    int p = co_i(k);
    return k - (p*(p + 1)/2);
}

int co_index(int i, int j){
    return (i*(i + 1)/2) + j;
}

int main(){
    int N;
    cout << "Enter the order of the Matrix : ";
    cin >> N;
    cout << "ARRAY A : \n";
    int n = N*(N+1)/2, A[n], B[n], C[n], index = 0, flag = 0, count = 1;
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }
    cout << "ARRAY B : \n";
    for(int i = 0; i < n; i++){
        cin >> B[i];
    }
    while(index < n){
        int sum = 0, i = co_i(index), j = co_j(index);
        for(int t = 0; t < N; t++){
            if( i >= t && t >= j ){
                sum = sum + A[co_index(i,t)]*B[co_index(t,j)];
            }
        }
        C[index] = sum;
        index++; 
    }
    cout << "ARRAY C : \n";
    for(int k = 0; k < n; k++){
        cout << C[k] << '\t';
        flag++;
        if(flag == count){
            count++;
            flag = 0;
            cout << endl;
        }
    }

    return 0;
}