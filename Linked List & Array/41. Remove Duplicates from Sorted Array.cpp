int removeDuplicates(vector<int> &nums, int n) {
	// Write your code here.
	int j=1, i=0;
	while( j<nums.size())
	{
		if(nums[i]!=nums[j])
		{
			i++;
			nums[i]=nums[j];
		}
		j++;
	}
	return i+1;
}