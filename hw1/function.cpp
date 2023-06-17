#include "function.h"
#include<iostream>
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
    if(c=='L') std::cout << "TR";
    else if(c=='R') std::cout << "TL";
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
void Queue::get_address(){std::cout << &(this->treasure) << std::endl;}