void sumSet(vector<vector<int>> &ans, vector<int>&set, int i,vector<int> arr, int n, int k)
{
    //base case
    if(n==0){
        if (k == 0){
            ans.push_back(set);
        }
        return;
    }
    //recurison
    //don't select element 
    sumSet(ans, set, i+1, arr, n-1, k);
    
    //select element
    set.push_back(arr[i]);
    sumSet(ans, set, i+1, arr, n-1, k-arr[i]);
    set.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>> ans;
    vector<int>set;
    sumSet(ans, set,0,arr,n,k);
    return ans;
}