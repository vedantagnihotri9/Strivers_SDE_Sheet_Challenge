bool isPossible(int node, int color[], vector<vector<int>> mat, int col, int n)
{
    for(int i=0; i<n;i++)
    {
        if(i!=node && mat[i][node]==1 && color[i]==col)
            return false;
    }

    return true;
}


bool sol(int node, int color[], vector<vector<int>> mat, int m, int n)
{
    //base 
    if(node==n)
        return true;
    
    //recursion
    for(int i=1;i<=m;i++)
    {
        if(isPossible(node, color, mat, i, n))
        {
            color[node]=i;
            if(sol(node+1, color, mat, m,n))
                return true;
            color[node]=0;
        }
    }
    return false;
}


string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n= mat.size();
    int color[n]={0};
    if(sol(0, color, mat, m,n))
        return "YES";
    else
        return "NO";
}