#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	sort(arr.begin(),arr.end());
	vector<vector<int>>ans;
	int i=0;
	for(i;i<n;i++)
	{
		if(i>0 && arr[i]==arr[i-1])
			continue;
		int k=n-1;
		int j=i+1;
		while(j<k)
		{
			if((arr[i]+arr[j]+arr[k])<K)
			{
				j++;
			}
			else if((arr[i]+arr[j]+arr[k])>K)
			{
				k--;		
			}
			else 
			{
				ans.push_back({arr[i],arr[j],arr[k]});
				k--;
				j++;
				while(arr[j]==arr[j-1])
					j++;
				while(arr[k]==arr[k+1])
					k--;
			}
		}
	}
	return ans;
}

//hashing solution
#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	//using set so that unique triplets are only added.
	set<vector<int>> st;
	for(int i=0;i<n;i++)
	{
		set<int> hash;
		for(int j=i+1;j<n;j++)
		{
			int th=K-arr[i]-arr[j];
			if(hash.find(th)!=hash.end())
			{
				vector<int>temp={arr[i],arr[j],th};
				sort(temp.begin(), temp.end());
				st.insert(temp);
			}
			hash.insert(arr[j]);
		}
	}
	vector<vector<int>> ans(st.begin(),st.end());
	return ans;
}