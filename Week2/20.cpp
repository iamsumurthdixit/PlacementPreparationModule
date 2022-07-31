class Solution {
public:
//     bool isSafe(int row, int col, vector<string>& board) {
//         int n = board.size();
//         for(int i = 0; i < col; i++) {
//             if(board[row][i] == 'Q') 
//                 return false; 
//         }
        
//         int dupRow = row, dupCol = col; 
//         while(row >= 0 && col >= 0) {
//             if(board[row--][col--] == 'Q')
//                 return false; 
//         }
//         row = dupRow; col = dupCol;
//         while(row < n && col >= 0) {
//             if(board[row++][col--] == 'Q') 
//                 return false;
//         }
//         return true; 
//     }
//     void solve(int col, int n, vector<string>&board, vector<vector<string>>&ans) {
//         if(col == n) {
//             ans.push_back(board);
//             return; 
//         }
//         for(int row = 0; row < n; row++) {
//             if(isSafe(row, col, board)) {
//                 board[row][col] = 'Q';
//                 solve(col + 1, n, board, ans);
//                 board[row][col] = '.';
//             }
//         }
//     }
    
    void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans, vector<int>& leftRow, vector<int>&leftUp, vector<int>& leftDown) {
        if(col == n) {
            ans.push_back(board); 
            return; 
        }
        for(int row = 0; row < n; row++) {
            if(leftRow[row] == 0 && leftDown[row+col] == 0 && leftUp[n-1+col-row] == 0) {
                leftRow[row] = 1; 
                leftDown[row + col] = 1; 
                leftUp[n - 1 + col - row] = 1; 
                
                board[row][col] = 'Q';
                solve(col + 1, n, board, ans, leftRow, leftUp, leftDown); 
                board[row][col] = '.';
                
                leftRow[row] = 0; 
                leftDown[row + col] = 0; 
                leftUp[n - 1 + col - row] = 0; 
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans; 
        vector<string> board(n);
        string s(n,'.');
        
        for(int i = 0; i < n; i++) {
            board[i] = s; 
        }
        // solve(0, n, board, ans);
        vector<int> leftRow(n,0), leftUp(2*n-1, 0), leftDown(2*n-1);
        solve(0,n,board,ans,leftRow,leftUp,leftDown);
        return ans; 
    }
};
