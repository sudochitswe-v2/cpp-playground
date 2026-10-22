#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void push(int stack[],int* top,int n,int val){
    if(*top == n-1){
        cout << "Stack Overflow" << endl;
        return;
    }
        *top++;
        stack[*top] = val;
}
void pop(int stack[], int* top){
    if(*top == -1){
        cout << "Stack Underflow" << endl;
        return;
    }
    *top--;
}
void top(int stack[], int* top){
    cout << stack[*top] << " ";
}


int main(){

    // int stack[6];
    // int top = -1;
    // push(stack, &top, top,13);
    // push(stack, &top, top,14);
    // print(stack, &top);

    stack<int> st;
    st.push(12);
    st.push(24);
    cout << st.top();
    return 0;
}