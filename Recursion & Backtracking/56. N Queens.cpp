//without using hashtable concept
bool isPossible(int row, int col, const vector<vector<int>> board, int n)
{
    //back up diagonal
    int c=col;
    int r=row;
    while(r>=0 and c>=0)
    {
        if(board[r][c]==1)
            return false;
        r--;
        c--;
    }

    //back
    c=col;
    r=row;
    while(c>=0)
    {
        if(board[r][c]==1)
            return false;
        c--;
    }

    //back down diagonal
    c=col;
    r=row;
    while(r<n and c>=0)
    {
        if(board[r][c]==1)
            return false;
        r++;
        c--;
    }

    return true;
}

void sol(int col,int n, vector<vector<int>>&board, vector<vector<int>>&ans)
{
    //base
    if(col==n)
    {
        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
        temp.clear();
        return;
    }

    //recursion
    for(int row=0;row<n;row++)
    {
        if(isPossible(row, col, board, n))
        {
            board[row][col]=1;
            sol(col+1, n, board, ans);
            board[row][col]=0;
        }
    }
}


vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    sol(0,n,board, ans);
    return ans;
}

---------------------------------------------------------------------------------------------------------------------------------------
//using hashtable concept
void sol(int col,int n, vector<vector<int>>&board, vector<vector<int>>&ans,vector<bool> &backRow, vector<bool> &upDiagonal,vector<bool> &downDiagonal)
{
    //base
    if(col==n)
    {
        vector<int>temp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                temp.push_back(board[i][j]);
            }
        }
        ans.push_back(temp);
        temp.clear();
        return;
    }

    //recursion
    for(int row=0;row<n;row++)
    {
        if(backRow[row]==0 && downDiagonal[row+col]==0 && upDiagonal[n-1+col-row]==0)
        {
            backRow[row]=1;
            downDiagonal[row+col]=1;
            upDiagonal[n-1+col-row]=1;
            board[row][col]=1;

            sol(col+1, n, board, ans, backRow, upDiagonal, downDiagonal);

            board[row][col]=0;
            backRow[row]=0;
            downDiagonal[row+col]=0;
            upDiagonal[n-1+col-row]=0;
        }
    }
}


vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<bool> backRow(n,0), upDiagonal(2*n-1,0), downDiagonal(2*n-1,0);
    sol(0,n,board, ans, backRow,upDiagonal,downDiagonal);
    return ans;
}