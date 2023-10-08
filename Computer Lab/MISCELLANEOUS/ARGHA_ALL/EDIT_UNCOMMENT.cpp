#include<iostream>
using namespace std;

int main(){
    int n1, n2;
    
    
    
    cout<<"Enter the size of the first array : ";
    cin>>n1;
    
        
    cout<<"Enter the size of the second array : ";
    cin>>n2;
    
    
    
    cout<<endl;
    
        
    int n3 = n1 + n2;
            int A[n1], B[n2], C[n3];
    
    

    for(int i = 0; i < n1; i++){
        cout<<"Enter the "<< i + 1 <<" element of the first array : ";
        cin>>A[i];
               }
    cout<<endl;
       
    for(int i = 0; i < n2; i++){
        cout<<"Enter the "<< i + 1 <<" element of the second array : ";
        cin>>B[i]; 
       }
       
    int A_ptr = n1 - 1;
    
    
    
    int B_ptr = n2 - 1;
        
        
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
    
    
    for(int i = 0; i < n3 ; i++){
        cout<<"\nElement "<< i + 1 <<" of the merged array\t: "<< C[i];
    }
    
        
    cout<<endl;
    
    return 0;
}
