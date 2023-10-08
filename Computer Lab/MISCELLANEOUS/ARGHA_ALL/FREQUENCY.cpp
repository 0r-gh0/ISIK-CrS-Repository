#include <iostream>
using namespace std;
int main()
{
    int temp, i = -1, count = 0, ARR[101] = {0};
    cout << "~: FREQUENCY OF N INPUT :~\n\n";
    cout << "PS: PRESS -1 to STOP" << endl << "PRESS ANY NUMBER BETWEEN 0-100" << endl;
    while(true){
        cout << "INPUT " << count + 1 << " : ";
        cin >> temp;
        if(temp == -1){
            cout << "DONE !\n";
            break;
        }
        if(temp < -1 || temp > 100){
            cout << "WARNING ! PLEASE ENTER A VALID NUMBER !\n";
            continue;
        }
        ARR[temp]++;
        count++;
    }
    cout << endl << "N | FREQUECY | BAR";
    while(i < 101){
        i++;
        if(ARR[i] == 0){continue;}
        cout << endl << i << "\t" << ARR[i] << "\t";
        for(int j = 0; j < ARR[i]; j++){cout << "*";}
    }
    return 0;
}