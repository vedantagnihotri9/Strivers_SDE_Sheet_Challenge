//my Approach
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    unordered_map<char ,int> strIndex;
    int count=0;
    int max=0;
    int i=0;
    while(i<input.size())
    {
        if(strIndex.find(input[i])==strIndex.end())
        {
            strIndex[input[i]]=i;
            count++;
            i++;
            if(max<count)
                max=count;
        }
        else
        {
            count=0;
            int newStartIndex=strIndex[input[i]]+1;
            i=newStartIndex;
            strIndex.clear();
        }
    }
    return max;
}


//Sliding Window
#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    unordered_set<char> strIndex;
    int count=0;
    int max=0;
    int i=0;
    int j=0;
    while(i<input.size() & j<input.size())
    {
        if(strIndex.find(input[i])==strIndex.end())
        {
            strIndex.insert(input[i]);
            count++;
            i++;
            if(max<count)
                max=count;
        }
        else
        {
            count=count-1;
            strIndex.erase(input[j]);
            j++;
        }
    }
    return max;
}