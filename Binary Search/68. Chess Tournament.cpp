#include <bits/stdc++.h> 
bool possible(vector<int> positions,int n,int c,int dist)
{
	int st=positions[0];
	int cnt=1;
	for(int i=1;i<n;i++)
	{
		if(positions[i]-st>=dist)
		{
			cnt++;
			st=positions[i];
		}
		if(cnt==c)
			return true;
	}
	return false;
}
int chessTournament(vector<int> positions , int n ,  int c){
	// Write your code here
	sort(positions.begin(),positions.end());
	int i=1;
	int j=positions[n-1]-positions[0];
	int ans;
	while(i<=j)
	{
		int mid =(i+j)/2;
		if(possible(positions,n,c,mid))
		{
			ans=mid;
			i=mid+1;
		}
		else
			j=mid-1;

	}
	return ans;
}