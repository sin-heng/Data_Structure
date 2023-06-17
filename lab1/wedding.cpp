#include<iostream>
#include<queue>
#include<stack>
#include<string>
using namespace std;
int main(void){
    char c;
    stack<string> parking;
    queue<int> table;
    string name;
    int tmp=0,cup=0,time_min=0,time_max=0;
    bool first = false;
    while(cin>>c){
        getchar();
        if(c=='R'){
            if(parking.empty()) first=true;
            getline(cin,name,' ');
            parking.push(name);
            cin >> time_max;
            if(first==true) time_min = time_max;
            first = false;
        }
        else if(c=='T'){
            cin >> tmp;
            table.push(tmp);
            cin >> tmp;
            cup+=tmp;
        }
        getchar();
    }
    while(!parking.empty()){
        cout << parking.top() << " ";
        parking.pop();
    }
    cout << endl << time_max-time_min << endl;
    while(!table.empty()){
        cout <<  table.front() << " ";
        table.pop();
    }
    cout << endl << cup << endl;
    return 0;
}