#include<iostream>
#include<vector>
using namespace std;

void dev(vector<int> &bin, int N){
    bin.push_back(N%2);
    if(N/2 != 0){return dev(bin,N/2);}
}

int main(){
    int N ;
    vector<int> bin;
    cout << "~: DECIMAL TO BINARY :~\n\n";
    cout << "PRESS (-1) TO STOP";
    while(true){
        cout << "\n\nENTER A NUMBER : ";
        cin >> N;
        if (N == -1){break;}
        cout << "BINARY FORM : ";
        dev(bin,N);
        for (int i = bin.size() - 1; i >= 0; --i){
            cout << bin[i];
        }
        bin.clear();
    }
    cout << "DONE !";
    return 0;
}