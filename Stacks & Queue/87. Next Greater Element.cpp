#include <bits/stdc++.h> 

vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int>s;
    for(int i=n-1;i>=0;i--)
    {
        while(s.empty()==false && s.top()<=arr[i])
        {
            s.pop();
        }
        if(s.empty()) 
        {
            s.push(arr[i]);
            arr[i] = -1;
            continue;
        }
        int x =s.top();
        s.push(arr[i]);
        arr[i]=x;
    }
    return arr;
}
----------------------------------------------------------------------------
//in circular
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        stack<int> s;
        for(int i=2*n-1; i>=0; i--)
        {
            while(!s.empty() && s.top()<=nums[i%n])
                s.pop();
            if(i<n)
            {
                if(!s.empty())
                    ans[i]=s.top();
                else
                    ans[i]=-1;
            }
            s.push(nums[i%n]);
        }
        return ans;
    }
};

//1,2,1,1,2,1
//stack= 2
//ans=[2, -1,2]