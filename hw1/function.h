#ifndef __FUNTION_H__
#define __FUNCTION_H__
#define MAX 100
class Stack{
    public:
        Stack(int capacity=MAX):top(-1){
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
        Queue(int capacity=MAX):front(-1),rear(-1){
            treasure = new char[capacity];
        }
        ~Queue(){delete [] treasure;}
        bool isEmpty() const;
        void push(const char c);
        char pop();
        void get_address();
    private:
        int front,rear;
        char* treasure;
        int capacity;
};
#endif