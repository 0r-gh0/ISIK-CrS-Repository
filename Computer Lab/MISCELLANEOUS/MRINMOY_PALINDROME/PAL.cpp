#include <iostream>
#include<string.h>
#include<fstream>
using namespace std;

int checked_palindrome(char a[20])
{
    int i,n;
    n = strlen(a);
    for (int i = 0; i < n/2; i++)
    {
        if(a[i] != a[n - 1 - i])
            break;
    }
    if(i == n/2)
       return 1;
    else
    {
      return 0;
    }
}

int main()
{

    ifstream inf;
    inf.open("SOURCE.txt");

    ofstream f_out;
    f_out.open("DSTN.txt");
    char a[20];
    int N,count=0;

    cout<<"\nEnter the value of N\n";
    cin>>N;
    while(inf)
    {
        inf>>a;
        if(strlen(a)>=N)
        {
            int p=checked_palindrome(a);
            if(p==1)
            f_out<<a<<"\n";
        }
        count++;
    }

    cout<<"\n\n count="<<count<<"\n";

    inf.close();
    f_out.close();
    
    return 0;
}
