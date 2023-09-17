#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && s.top()>=arr[i])
        {
            s.pop();
        }
        if(s.empty())
        {
            s.push(arr[i]);
            arr[i]=-1;
            // continue;
        }
        else
        {
            int m=s.top();
            s.push(arr[i]);
            arr[i]=m;
        }
    }
    return arr;
}