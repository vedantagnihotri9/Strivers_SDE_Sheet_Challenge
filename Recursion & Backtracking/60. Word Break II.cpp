#include <bits/stdc++.h>
bool find(string word, vector<string>dictionary)
{
    for(int i=0;i<dictionary.size(); i++)
    {
        if(word==dictionary[i])
            return true;
    }
    return false;
}

void breaks(int index, string &s, vector<string> &dictionary, string &sent, vector<string> &ans) 
{
    //base case
    if(index==s.size())
    {
        ans.push_back(sent);
        return;
    }
    //recursion
    string word="";
    for(int i=index;i<s.size();i++)
    {
        word=word+s[i];
        if(find(word, dictionary))
        {
            string x=sent;
            sent=sent+word+" ";
            breaks(i+1, s, dictionary, sent, ans);
            sent = x;
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string> ans;
    string sent;
    breaks(0, s, dictionary, sent, ans);
    return ans;
}