#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int *arr;
    int curr;
    int size;
public:
    
    Stack(int capacity) {
        // Write your code here.
        this->size=capacity;
        arr= new int[size];
        curr=-1;
    }

    void push(int num) {
        // Write your code here.
        if(size-curr>1)
        {
            curr++;
            arr[curr]=num;
        }
    }

    int pop() {
        // Write your code here.
        if (curr != -1) {
          int ans = arr[curr];
          curr--;
          return ans;
        }
        else
            return -1;
    }
    
    int top() {
        // Write your code here.
        if(curr!=-1)
            return arr[curr];
        else
            return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        if(curr==-1)
            return 1;
        else
            return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(curr==size-1)
            return 1;
        else
            return 0;
    }
    
};