#include <iostream>
#include <vector>
using namespace std;

int main(){
    string temp;
    int count1 = 0, count2 = 0;
    vector<int> A1,B1;
    cout << "~: MERGING TWO SORTED ARRAYS :~\n\nP.S. Press N or n to stop accepting\n";
    cout<<"ENTER THE FIRST SORTED ARRAY\n";
    while(true)
    {
        cout << "1st ARRAY, ELEMENT " << count1 + 1 << " :\t";
        cin >> temp;
        if(temp == "N" || temp == "n"){cout << "DONE WITH 1st ARRAY !\n";break;}
        if(count1 >= 1){if(A1.back() > stoi(temp)){cout << "ARRAY IS NOT SORTED ! ENTER NEXT ELEMENT\n"; continue;}}
        A1.push_back(stoi(temp));
        count1++;
    }

    cout<<"\nENTER THE SECOND SORTED ARRAY\n";
    while(true)
    {
        cout << "2nd ARRAY, ELEMENT " << count2 + 1 << " :\t";
        cin >> temp;
        if(temp == "N" || temp == "n"){cout << "DONE WITH 2nd ARRAY !\n";break;}
        if(count2 >= 1){if(B1.back() > stoi(temp)){cout << "ARRAY IS NOT SORTED ! ENTER NEXT ELEMENT\n"; continue;}}
        B1.push_back(stoi(temp));
        count2++;
    }
    int n3 = count1 + count2, A[count1], B[count2], C[n3];

    copy(A1.begin(),A1.end(),A);
    copy(B1.begin(),B1.end(),B);

    int A_ptr = count1 - 1, B_ptr = count2 - 1;
        
    for(int i = 0; i < n3; i++){
        if(A[A_ptr] <= B[B_ptr] && B_ptr >= 0){
            C[i] = B[B_ptr];
            B_ptr--;
            continue;
        }
    
        if(B[B_ptr] < A[A_ptr] && A_ptr >= 0){
            C[i] = A[A_ptr];
            A_ptr--;
            continue;
        }
        
        if(A_ptr < 0){
            C[i] = B[B_ptr];
            B_ptr--;
            continue;
        }
        
        if(B_ptr < 0){
            C[i] = A[A_ptr];
            A_ptr--;
            continue;
        }
    }
    
    cout << "\nTHE MERGED ARRAY";
    for(int i = 0; i < n3 ; i++){
        cout<<"\nMERGED ARRAY ELEMENT "<< i + 1 <<"\t:  "<< C[i];
    }
    return 0;
}