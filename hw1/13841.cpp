#include<iostream>
#include "function.h"
#include<string.h>
using namespace std;
int count(int,int);
int main(void){
    char str[10];
    char c;
    int miss,gold,silver,total;
    Stack stack;
    Queue queue,queue_c; // queue_c for copy
    while(cin.getline(str,9)&&strlen(str)!=0){
        if(str[0] == 'T') stack.push(str[1]);
        else queue.push(str[0]);
    }
    // stack
    stack.pop();
    while(!stack.isEmpty()){
        cout << "->";
        stack.pop();
    }
    cout << endl;
    // queue
    queue_c = queue;
    miss=0;silver=0;gold=0,total=0;
    while(!queue.isEmpty()){
        c = queue.pop();
        if(c == 'M') miss=4;
        else if((c == 'G' || c == 'S') && miss!=0) miss--;
        else if(c == 'G' && miss == 0) gold++;
        else if(c == 'S' && miss == 0 ) silver++;
        if(gold+silver==3){
            total+=count(silver,gold);
            silver=0;gold=0;
        }
    }
    cout << total << endl;
    silver=0;gold=0,total=0;
    while(!queue_c.isEmpty()){
        c = queue_c.pop();
        if(c == 'G') gold++;
        else if(c == 'S') silver++;
        if(gold+silver==3){
            total+=count(silver,gold);
            silver=0;gold=0;
        }
    }
    cout << total << endl;
    return 0;
}
int count(int s,int g){
    if(g==3) return 500;
    else if(g==2) return 300;
    else if(g==1) return 150;
    else return 50;
}