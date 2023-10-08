#include<iostream>
using namespace std;

int main(){
    int n1, n2;
    
    /* MCOMMENT1
     */
    
    cout<<"Enter the size of the first array : ";
    cin>>n1;
    
    // COMMENT1
    
    cout<<"Enter the size of the second array : ";
    cin>>n2;
    
    /* MCOMMENT2 
    HELLO 123*/
    
    cout<<endl;
    
    // COMMENT2
    
    int n3 = n1 + n2;
    /* MCOMMENT2.5// */    //Hello world
    int A[n1], B[n2], C[n3];
    
    /* MCOMM
    ENT3 */

    for(int i = 0; i < n1; i++){
        cout<<"Enter the "<< i + 1 <<" element of the first array : ";
        cin>>A[i];
        // COMMENT3
       }
    cout<<endl;
       
    for(int i = 0; i < n2; i++){
        cout<<"Enter the "<< i + 1 <<" element of the second array : ";
        cin>>B[i]; /* MCOMMENT4 */
       }
       
    int A_ptr = n1 - 1;
    
    /* MCOMMENT5 */
    
    int B_ptr = n2 - 1;
        
    // COMMENT4
    
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
    
    //COMMENT 5
    
    cout<<endl;
    
    return 0;
}
