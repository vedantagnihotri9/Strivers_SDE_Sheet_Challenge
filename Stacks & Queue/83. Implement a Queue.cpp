//using vector
#include <bits/stdc++.h> 
class Queue {
    vector<int> arr;
    // int size;
    int tail;
    // int top;
public:
    Queue() {
        // Implement the Constructor
        // size=0;
        // top=0;
        tail=-1;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(tail<0)
            return true;
        return false;
        
    }

    void enqueue(int data) {
        // Implement the enqueue() function
            tail++;
            arr.push_back(data);
    }

    int dequeue() {
        // Implement the dequeue() function
        if(tail<0)
            return -1;
        int ans=arr[0];
        arr.erase(arr.begin());
        tail--;
        return ans;
    }

    int front() {
        // Implement the front() function
        if(tail<0)
            return -1;
        return arr[0];
    }
};

//using linked list
#include <bits/stdc++.h>

class qNode{
public:
    int val;
    qNode* next;
    qNode(int a){
        val=a;
        next = NULL;
    } 
};

class Queue {
    qNode *tail;
    qNode *top; 
public:
    Queue() {
        // Implement the Constructor
        tail=NULL;
        top=NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(top==NULL)
            return true;
        return false;
        
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        qNode *node=new qNode(data);
        if(top==NULL)
        {
            top=node;
            tail=top;
        } else {
          tail->next = node;
          tail = node;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(top==NULL)
            return -1;
            
        int ans=top->val;
        top=top->next;
        return ans;
    }

    int front() {
        // Implement the front() function
        if(top==NULL)
            return -1;
        return top->val;
    }
};