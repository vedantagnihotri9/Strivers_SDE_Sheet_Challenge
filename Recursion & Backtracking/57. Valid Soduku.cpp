bool isPossible(char c, int board[9][9], int row, int col)
{
    //check row //check col //check submatrix
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==c)
                return false;
            if(board[col][i]==c)
                return false;
            
            if (board[(3 * (row / 3)) + (i / 3)][(3 * (col / 3)) + (i % 3)] == c)
                return false;
        }
        return true;
}

bool sol(int board[9][9])
{
    for (int i = 0; i < 9; i++) 
    {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                for (int c = 1; c <= 9; c++) {
                    if (isPossible(c, board, i, j)) {
                        board[i][j] = c;
                        if (sol(board))
                            return true;
                        else
                            board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}
bool isItSudoku(int board[9][9]) {
   return sol(board);
}
