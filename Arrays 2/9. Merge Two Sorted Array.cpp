#include <bits/stdc++.h>

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int i=m-1; 
	int j=0;
	// int k=0;
	while(i>=0 and j<n)
	{
		if(arr1[i]>arr2[j])
		{
			swap(arr1[i],arr2[j]);
			i--;
			j++;
        } 
		else 
			break;
    }
	sort(arr1.begin(),arr1.begin()+m);
	sort(arr2.begin(),arr2.end());

	int k=0;
	for(int i=0;i<n;i++)
	{
		arr1[i+m]=arr2[k];
		k++;
	}
	return arr1;
}