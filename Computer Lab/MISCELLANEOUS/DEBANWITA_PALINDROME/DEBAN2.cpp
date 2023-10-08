#include<iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter a value for N : ";
    cin>>n;
    int temporary, givenArray[n];
    cout << "\nEnter "<<n<<" values between 0 to 100. "<<endl;
    for(int i = 0; i < n; i++)
    {
        cin>>givenArray[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j=i;j<n;j++)
        if(givenArray[i]<=givenArray[j])
        continue;
        else
        { temporary=givenArray[i];
        givenArray[i]=givenArray[j];
        givenArray[j]=temporary;
        }
    }

    int count[n];
    int temp[n]; //copy givenArray to temp
    for(int j=0;j<n;j++)
    temp[j]=givenArray[j];
    for(int k=0;k<n;k++)
    {   if(temp[k]<=100 && temp[k]>=0)
         {count[k]=1;
        for(int l=k+1;l<n;l++)
        {
        if(temp[l]<=100 && temp[l]>=0 && temp[k]==temp[l])
        {temp[l]=101;
        count[k]++;
        }}}
    }    
   for(int k=0;k<n;k++)
       if(temp[k]<=100 && temp[k]>=0)
            {cout<<givenArray[k]<<"   ";
             for(int i=0;i<count[k];i++)
             cout<<"*";
             cout<<" ..... "<<"("<<count[k]<<")"<<endl;
            }
    return 0;
}
