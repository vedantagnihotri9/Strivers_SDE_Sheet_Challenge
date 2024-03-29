#include <bits/stdc++.h>

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
    int row=0;
    int col=0;
    int mR=n-1;
    int mC=m-1;

    while(row<mR && col<mC)
    {
        int previous=mat[row+1][col];
        //1st row
        for(int i=col;i<=mC;i++)
        {
            int current=mat[row][i];
            mat[row][i]=previous;
            previous=current;
        }
        row++;
        //last column
        for(int i=row;i<=mR;i++)
        {
            int current=mat[i][mC];
            mat[i][mC]=previous;
            previous=current;
        }
        mC--;
        //last row
        for(int i=mC;i>=col;i--)
        {
            int current=mat[mR][i];
            mat[mR][i]=previous;
            previous=current;
        }
        mR--;
        //1st column
        for(int i=mR;i>=row;i--)
        {
            int current=mat[i][col];
            mat[i][col]=previous;
            previous=current;
        }
        col++;
    }    
}