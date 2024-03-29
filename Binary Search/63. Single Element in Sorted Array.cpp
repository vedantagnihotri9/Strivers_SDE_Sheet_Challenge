int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int i=0;
	int n=arr.size();
	int j=n-1;
	while(i<=j)
	{
		int mid = (i+j)/2;

		if((mid==0||arr[mid]!=arr[mid-1]) && (mid==n-1||arr[mid]!=arr[mid+1]))
		{
			return arr[mid];
		}
		//check mid element is before req ans
		if((mid%2==1 && arr[mid]==arr[mid-1]) || (mid%2==0 && arr[mid]==arr[mid+1]))
		{
			i=mid+1;
		}
		else
			j=mid-1;
	}
}