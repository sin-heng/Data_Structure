#include<iostream>
#include<string.h>
using namespace std;
#define MAX 100
// class template
class Stack{
    public:
        Stack(int capacity=MAX):top(-1),capacity(capacity){
            route = new char[capacity];
        }
        ~Stack(){delete []route;}
        bool isEmpty() const;
        void push(const char c);
        void pop();
    private:
        int top;
        char* route;
        int capacity;
};  
class Queue{
    public:
        Queue(int capacity=MAX):front(-1),rear(-1),capacity(capacity){
            treasure = new char[capacity];
        }
        ~Queue(){delete [] treasure;}
        bool isEmpty() const;
        void push(const char c);
        char pop();
    private:
        int front,rear;
        char* treasure;
        int capacity;
};
int count(int,int);
int main(void){
    char str[11];
    char c;
    int miss,gold,silver,total;
    Stack stack;
    Queue queue,queue_c; // queue_c for copy
    while(cin.getline(str,10)&&strlen(str)!=0){
        if(str[0] == 'T') stack.push(str[1]);
        else if(str[0]!='K'){ 
            queue.push(str[0]);
            queue_c.push(str[0]);
        }
    }
    // stack
    stack.pop();
    while(!stack.isEmpty()){
        cout << "->";
        stack.pop();
    }
    cout << endl;
    // queue
    // treasure value with miss
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
    // treasure value without miss
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
// member functions
bool Stack::isEmpty() const{
    if(top==-1) return true;
    else return false;
}
void Stack::push(const char c){
    if(top==capacity-1) return;
    route[++top] = c;
}
void Stack::pop(){
    char c = route[top--];
    if(c=='L') cout << "TR";
    else if(c=='R') cout << "TL";
}
bool Queue::isEmpty() const{
    if(rear==front) return true;
    else return false;
}
void Queue::push(const char c){
    if(rear==capacity-1) return;
    if(c=='G' || c=='M' || c=='S') treasure[++rear] = c;
}
char Queue::pop(){return treasure[++front];}