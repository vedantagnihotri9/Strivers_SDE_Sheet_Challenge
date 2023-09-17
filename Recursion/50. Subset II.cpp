#include <bits/stdc++.h> 
//recursion
void sumSubset(vector<int> &arr, int ind, vector<int> &ds,vector<vector<int>> &ans )
{
    ans.push_back(ds);
    for(int i=ind; i<arr.size();i++)
    {
        if(i!=ind and arr[i]==arr[i-1])
            continue;
        ds.push_back(arr[i]);
        sumSubset(arr, i+1,ds, ans);
        ds.pop_back();
    }

}
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> ds;
    int index=0;
    sort(arr.begin(), arr.end());
    sumSubset(arr, index, ds, ans);
    return ans;
}