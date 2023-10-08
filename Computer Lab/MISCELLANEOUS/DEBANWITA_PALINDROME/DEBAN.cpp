#include<iostream>
#include<fstream>
#include<stack> //including the stack header file to use the stack<string> command later>
#include<string>
using namespace std;
bool ispal(string str) //function to check if a string is palindrome
{
    int i, j=str.length()-1;
    for(i=0;i<=j;i++)
    {
        if(str[i]==str[j-i])
        continue;
        else {
            return 0; break;
        }
    }
    return 1;
}


int main()
{   string infile, outfile;
    cout<<"what is the input file path?";
    getline(cin, infile);
    ifstream inputFile(infile);
    if(!inputFile){
        cerr<< "none like that";
        return 1;
    }
    cout<<"what is the output file path?";
    getline(cin, outfile);
    ofstream outputFile(outfile);
    
    if (!outputFile) {
        cerr << "Error: Could not create the output file." << endl;
        return 1;
    }
    
    stack<string> stackofpal;
    int n;
    cout<<endl<<"Enter the value of N?"<<endl;
    cin>>n;

    string word;
    while(inputFile>>word)  //'word' is the variable for the strings in file. the loop goes on as it is tracing words till file ends or sees andy error
    {
        if(word.length()>=n) // at first we pass through the check of string length
        {if(ispal(word))    //then we check if it is palindrome, if yes, we put in stack
        stackofpal.push(word);
          }
    }

    
    while(!stackofpal.empty())
    {
        outputFile<<stackofpal.top()<<" ";
        stackofpal.pop();
    }


    cout<<"The reverse ordered stack is written on"<<outfile;
    

    inputFile.close();
    outputFile.close();
return 0;
    
}