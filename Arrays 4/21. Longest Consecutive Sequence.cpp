//my solution

#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    sort(arr.begin(),arr.end());
    int count=1;
    int maxi=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]==arr[i])
            continue;
        if(arr[i-1]+1==arr[i])
        {
            count++;
            maxi=max(count,maxi);
        }
        else
        {
            count=1;
        }
    }
    return maxi;
}

// O(n) space and time
#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    // Write your code here.
    // sort(arr.begin(),arr.end());
    unordered_set<int> elements;
    int count=1;
    int maxi=1;
    for(int i=0;i<n;i++)
        elements.insert(arr[i]);

    for(int i=0;i<n;i++)
    {
        if(elements.find(arr[i]-1)==elements.end())
        {
            int j=arr[i];
            count=0;
            while(elements.find(j)!=elements.end())
            {
                count++;
                j++;
            }
            maxi=max(maxi,count);
        }
    }
    return maxi;
}
