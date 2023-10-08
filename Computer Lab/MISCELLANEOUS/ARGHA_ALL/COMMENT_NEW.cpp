#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int flag = 0;
    char curr, prev, ptr;
    vector<string> lines;
    string fin, fout, char1, end1 = "00";
    
    cout << "~: COMMENTS REMOVING :~\n\n";
    cout << "INPUT FILE NAME : ";
    getline(cin, fin);
    ifstream fptr2(fin);

    if (!fptr2)
    {
        cerr << "ERROR : No such file found!" << endl;
        return -1;
    }

    cout << "OUTPUT FILE NAME : ";
    getline(cin, fout);
    ofstream fptr1(fout);
 
    while (fptr2.get(ptr)) {
        char temp = end1[0];
        end1[0] = ptr;
        end1[1] = temp;

        if(flag == 0){
            curr = ptr; 
            if(curr == '/' || curr == '*'){
                if (prev == '/')     
                {
                    if((ptr != '\n' && curr == '/') || curr == '*'){
                        flag = 1;
                    }
                }
            }
            prev = curr;
            fptr1.put(curr); 
        }
        else
        {
            if((curr == '/' && ptr == '\n') || (curr == '*' && end1 == "/*")){
                flag = 0;
                fptr1.seekp(-2, ios::cur );
            }
        }
    }
    
    fptr1.close();
    fptr2.close();

    cout << "\nCOMMENTS REMOVED !"<< endl << "PLEASE CHECK THE FILE : " << fout;
    return 0;
}