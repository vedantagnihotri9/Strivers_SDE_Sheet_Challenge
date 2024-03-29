//bool visited approach

#include <bits/stdc++.h>
void permutations(string s, int index, string &perm, vector<string> &ans, bool v[])
{
    //base
    if(index==s.size())
    {
        ans.push_back(perm);
        return;
    }
    //recursion
    for(int i=0;i<s.size();i++)
    {
        if(v[i]!=1)
        {
            v[i]=1;
            perm += s[i];
            permutations(s, index + 1, perm, ans, v);
            perm.pop_back();
            v[i]=0;
        }        
    }
} 

vector<string> findPermutations(string &s) {
    // Write your code here.
    
    string perm;
    vector<string> ans;
    if(s.empty())
        return ans;
    bool v[s.size()]={0};
    permutations(s,0,perm,ans, v);
    return ans;
}


//swapping approach
#include <bits/stdc++.h>
void permutations(string &s, int index, vector<string> &ans)
{
    //base
    if(index==s.size())
    {
        ans.push_back(s);
        return;
    }
    //recursion
    for(int i=index;i<s.size();i++)
    {
        swap(s[i],s[index]);
        permutations(s, index + 1, ans);
        swap(s[i],s[index]);
    }
} 

vector<string> findPermutations(string &s) {
    // Write your code here.
    
    vector<string> ans;
    if(s.empty())
        return ans;
    
    permutations(s,0,ans);
    return ans;
}
