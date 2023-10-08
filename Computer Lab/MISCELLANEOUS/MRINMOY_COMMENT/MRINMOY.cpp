#include <iostream>
#include<string.h>
#include<fstream>
using namespace std;

string removeComments(const string &s)
{
    int n=s.length();;
    string s1;
    //We know that two types of comments one is single line comment and other is multiple line comment
    //flag for single line comment and Multiple line comment
    bool s_com=false;
    bool m_com=false;

    for(int i=0;i<n;i++)
    {
        if(s_com==true && s[i]=='\n')
        {
            s_com=false;i++;
        }
            else if(m_com==true && s[i]=='*' && s[i+1]=='/')
            {
                 m_com=false;i++;
            }
            else if(m_com==true || s_com==true)
                continue;
            else if(s[i]=='/' && s[i+1]=='/')
                s_com=true;
            else if(s[i]=='/' && s[i+1]=='*')
                m_com=true;
                else  s1 += s[i];
    }
    return s1;
}

int main()
{
    string input_file_name, output_file_name;
    
    cout << "Enter the input file name : ";
    cin >> input_file_name;
    ifstream fin(input_file_name);

    if(!fin)
    {
        cerr<<"\nNo Such file found !\n";
        return -1;
    }

    cout << "\nEnter the output file name : ";
    cin >> output_file_name;
    
    ofstream fout(output_file_name);
    string prgm;

    while(getline(fin,prgm))
    {
        string result = removeComments(prgm);
        fout << result << endl;
    }

    cout << "\nCOMMENTS REMOVED !" << endl << "Please check the file : " << output_file_name;

    fin.close();
    fout.close();
    
    return 0;
}