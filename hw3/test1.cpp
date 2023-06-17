#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
int main(void){
    int star;
    char ch;
    while(true){
        cin >> ch;
        if(ch=='S'){
            cout << "s path\n";
            while(ch!='>') cin >> ch;
            cin >> ch;
            cin >> star;
            cout << "star: " << star << endl;
        }
        else if(ch=='A'){
            cout << "a path\n";
        }
        else if(ch=='T'){
            cout << "t path\n";
            break;
        }
        while(ch!='\n') cin >> ch;
    }
    return 0;
}