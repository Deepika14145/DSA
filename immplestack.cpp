#include<iostream>
using namespace std;

class Stack{
    public:
    int top;
    int *arr;
    int size;

    Stack(){
        top = -1;
        size = 10;
        arr = new int[size];
    }

    void push(int x){
        arr[top] = x;
    }

    int pop(){
        int x = arr[top];
        top--;
        return x;
    }

    int Top(){
        return arr[top];
    }

    int size(){
        return top+1;
    }
};