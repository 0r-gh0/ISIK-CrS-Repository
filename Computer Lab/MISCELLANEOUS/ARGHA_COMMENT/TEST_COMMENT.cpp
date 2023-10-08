#include<iostream>
#include<fstream>

using namespace std;

int main(){

    fstream fptr1, fptr2;
    
    //fptr1.open("TECH1.txt");
    fptr2.open("TECH2.txt");
    //fptr3.open("TECH2.txt");

    //fptr1.open("UNCOMMENT.cpp");
    //fptr2.open("EDIT.cpp");
    
    if (fptr2.fail())
	{
		cerr << "Files couldn't be found !";
		return 1;
	}
	
	char my_char, my_char2, temp_char;
	int count = 0;


    fptr2.seekg(0);
/*
    int temp = fptr2.tellg();   //Get the pos of File Pointer
    fptr3.seekg(temp + 1);      //Get the next position
    cout<<fptr2.tellg()<<'\t'<<fptr3.tellg()<<endl;
    
    temp_char = fptr3.get();       //Access the charactar of the next position
    my_char2 = fptr2.get();
    cout<<endl<<my_char2<<'\t'<<temp_char<<endl;
*/  
    while (fptr2.get(my_char2)) {
        //cout<<my_char2;

        //my_char = fptr2.get();
        auto pos = fptr2.tellg();

        cout<<my_char2<<'\t'<<pos<<endl;

        /*
        if(my_char2 == '/'){

            int temp = fptr2.tellg();   //Get the pos of File Pointer
            //cout<<temp<<endl;
            fptr3.seekg(temp + 1);      //Get the next position
            cout<<fptr2.tellg()<<'\t'<<fptr3.tellg()<<endl;

            temp_char = fptr3.get();       //Access the charactar of the next position
            cout<<endl<<temp_char<<"\tHI"<<endl;
            cout<<endl<<my_char2<<'\t'<<temp_char<<endl;

            if (temp_char == '/')      //If it happens to be 2 Backward Slashes OR Comments
            {
                cout<<"INSIDE !";
                
            }
        }
        fptr1.put(my_char2); 
        */
    }
    
    //fptr1.close();
    fptr2.close();
    //fptr3.close();
    
    cout<<"\nDONE !";

    return 0;
        
}
