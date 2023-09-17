//Amortized O(1) sol
#include<stack>
class Queue {
    // Define the data members(if any) here.
    stack<int>inp,outp;
    // int size;
    
    public:
    Queue() {
        // Initialize your data structure here.
        // size=0;
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        inp.push(val);
    }

    int deQueue() {
        // Implement the dequeue() function.
        if(outp.empty())
        {
            while(!inp.empty())
            {
                outp.push(inp.top());
                inp.pop();
            }
        }
        if(outp.empty())
            return -1;
        int ans=outp.top();
        outp.pop();
        return  ans;
    }

    int peek() {
        // Implement the peek() function here.
        if(outp.empty())
        {
            while(!inp.empty())
            {
                outp.push(inp.top());
                inp.pop();
            }
        }
        if(outp.empty())
            return -1;
        return outp.top();
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        if(inp.empty() && outp.empty())
            return true;
        return false;
    }
};




//2nd Sol
#include<stack>
class Queue {
    // Define the data members(if any) here.
    stack<int>s1,s2;
    int size;
    
    public:
    Queue() {
        // Initialize your data structure here.
        size=0;
    }

    void enQueue(int val) {
        // Implement the enqueue() function.
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deQueue() {
        // Implement the dequeue() function.
        if (!s1.empty()) {
          int ans=s1.top();
          s1.pop();
          return ans;
        }
        return -1;
    }

    int peek() {
        // Implement the peek() function here.
        if(!s1.empty())
            return s1.top();
        return -1;
    }

    bool isEmpty() {
        // Implement the isEmpty() function here.
        if(s1.empty())
            return true;
        return false;
    }
};
