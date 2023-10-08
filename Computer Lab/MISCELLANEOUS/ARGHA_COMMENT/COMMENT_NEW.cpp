#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){

    fstream fptr1, fptr2;
    
    fptr1.open("DSTN.cpp");
    fptr2.open("SOURCE.cpp");
    
    if (fptr1.fail() || fptr2.fail())
	{
		cerr << "Files couldn't be found !";
		return 1;
	}
	
	char curr, prev, ptr;
    string end1 = "00";
	int flag = 0;
 
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

    cerr<<"COMMENTS REMOVED !\n";

    return 0;
        
}
