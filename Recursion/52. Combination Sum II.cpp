#include <algorithm>


void sets(vector<int> arr, int ind, int n, int target,vector<int> &ds, vector<vector<int>>&ans)
{
	
	if(target==0)
	{
		ans.push_back(ds);
		return;
	}
	
	
	
	for (int i = ind; i < n; i++) 
	{
		if(i>ind && arr[i]==arr[i-1])
			continue;
		// select element
		if (target<arr[i])
			break;

		ds.push_back(arr[i]);
		sets(arr, i + 1, n , target - arr[i], ds, ans);
		ds.pop_back();
    }
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	vector<vector<int>>ans;
	vector<int>ds;
	sort(arr.begin(), arr.end());
	sets(arr, 0, n, target, ds, ans);
	return ans;
}
