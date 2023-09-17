#include <bits/stdc++.h>

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
	vector<int> freq(n,0);
	for(int i=0;i<n;i++)
	{
		freq[arr[i]-1]++;
	}
	int r=0,m=0;
	for(int i=0;i<n;i++)
	{
		if(freq[i]!=1)
		{
			if(freq[i]==0)
				m=i+1;
			else
				r=i+1;
		}
		if(r!=0 && m!=0)
			break;
	}
	return {m,r};
}
