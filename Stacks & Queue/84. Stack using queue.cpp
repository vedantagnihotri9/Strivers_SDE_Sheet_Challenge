#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int> q1, q2;
    int size;

   public:
    Stack() {
        // Implement the Constructor.
        size=0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function.
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        if(size==0)
            return true;
        return false;
    }

    void push(int element) {
        // Implement the push() function.
        q2.push(element);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
        size++;
    }

    int pop() {
        // Implement the pop() function.
        if(size!=0)
        {
            int ans=q1.front();
            q1.pop();
            size--;
            return ans;
        }
        return -1;
    }

    int top() {
        // Implement the top() function.
        if(!q1.empty())
            return q1.front();
        return -1;
    }
};