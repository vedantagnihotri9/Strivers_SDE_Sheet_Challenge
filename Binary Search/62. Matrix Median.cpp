int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int low = 1;
    int high = 1e5;
    int n=matrix.size();
    int m=matrix[0].size();
    while(low<=high)
    {
        int mid=(low+high)/2;
        //count number of elements small than equal to mid
        int cnt=0;
        for(int i=0;i<n; i++)
        {
            int l=0, h=matrix[i].size()-1;
            while(l<=h)
            {
                int m=(l+h)/2;
                if(matrix[i][m]<=mid)
                    l=m+1;
                else
                    h=m-1;
            }
            cnt=cnt+l;
        }

        if(cnt<=(n*m)/2)
            low=mid+1;
        else
            high =mid-1;
    }
    return low;
}