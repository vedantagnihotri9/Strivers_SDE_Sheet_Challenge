#include <bits/stdc++.h>

int findDuplicate(vector<int> &arr, int n){
	// Write your code here.
	unordered_set<int> ele;
	for(int i=0;i<n;i++)
	{
		if(ele.find(arr[i])==ele.end())
			ele.insert(arr[i]);
		else
			return arr[i];
	}

	return -1;
}
