#include<iostream>
#include<string>
#include<fstream>
using namespace std;

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
    char curr_char,pre_char='\0';
    while(fin.get(curr_char))
    {
    //We know that two types of comments one is single line comment and other is multiple line comment
    //flag for single line comment and Multiple line comment
    bool s_com=false;
    bool m_com=false;
   
        if(s_com==true && curr_char=='\n')
        {
            s_com=false;
        }
            else if(m_com==true && pre_char=='*' && curr_char=='/')
            {
                 m_com=false;
            }
            else if(m_com==true || s_com==true)
            {
                pre_char=curr_char;
                continue;
            }
            else if(pre_char=='/' && curr_char=='/')
                s_com=true;
            else if(pre_char=='/' && curr_char=='*')
                m_com=true;
                else   fout.put(pre_char);
                pre_char=curr_char;
    }

    cout << "\nCOMMENTS REMOVED !" << endl << "Please check the file : " << output_file_name;

    fin.close();
    fout.close();
   
    return 0;
}