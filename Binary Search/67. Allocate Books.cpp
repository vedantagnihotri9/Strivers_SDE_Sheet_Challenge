#include <bits/stdc++.h> 
bool possible(int n, int m, vector<int> time, long long int mid)
{
	long long int day=1;
	long long int chap=0;
	for(int i=0;i<m;i++)
	{
		if(time[i]>mid)
			return false;
		if(time[i]+chap>mid)
		{
			day++;
			chap=time[i];
		}
		else
			chap+=time[i];
	}
	if(day>n)
		return false;
	return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	// Write your code here.
	long long int mini=1000000000;
	for(int i=0;i<m;i++)
	{
		if(mini>time[i])
			mini=time[i];
	}
	
	long long int sum=0;
	for(int i=0;i<m;i++)
		sum+=time[i];
	
	long long int i=mini;
	long long int j=sum;
	long long int ans;
	while(i<=j)
	{
		long long int mid=(i+j)/2;
		if(possible(n, m, time, mid))
		{
			ans=mid;
			j=mid-1;
		}
		else
			i=mid+1;
	}
	return ans;
}