bool searchMatrix(vector<vector<int>>& mat, int target) {
    int r = mat.size();
    int c = mat[0].size();
    int i=0; 
    int j= r*c -1;
    while(i<=j)
    {
        int mid = (i+j)/2;
        int x = mid/c;
        int y = mid%c;
        if(mat[x][y]==target)
            return true;
        if(mat[x][y]<target)
            i=mid+1;
        else 
            j=mid-1;
    }
    return false;
}