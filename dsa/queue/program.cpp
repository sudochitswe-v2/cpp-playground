#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int size;
public:
    Queue(int n){
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    void push(int x){
        if(rear == size-1){
            cout << "Queue Overflow" << endl;
            return;
        }
        else if(front == -1 && rear == -1){
            front = rear = 0;
            arr[rear] = x;
        }
        else{
            rear++;
            arr[rear] = x;
        } 
    }
    int pop(){
        if(front == -1 || front > rear){
            cout << "Queue Underflow" << endl;
            return -1;
        }
        else{
            int x = arr[front];
            front++;
            return x;
        }
    }
    int front(){
        if(front == -1){
            cout << "Queue is empty" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }
    int back(){
        if(rear == -1){
            cout << "Queue is empty" << endl;
            return -1;
        }
        else{
            return arr[rear];
        }
    }
    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        return rear == size-1;
    }
};


int main() {
    Queue q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.pop() << endl; // Output: 1
    cout << q.pop() << endl; // Output: 2
    cout << q.pop() << endl; // Output: 3
    cout << q.pop() << endl; // Output: Queue Underflow
    return 0;
}