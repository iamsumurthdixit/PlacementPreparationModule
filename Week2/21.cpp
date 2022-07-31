class Solution {
public:
    void solveSudoku(vector<vector<char>>& sudoku) {
        solve(sudoku);
    }
    
    bool solve(vector<vector<char>>& sudoku) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(sudoku[i][j] == '.') {
                    
                    for(char k = '1'; k <= '9'; k++) { 
                        if(isValid(sudoku, i, j, k)) {
                            sudoku[i][j] = k;
                            
                        if(solve(sudoku))
                            return true; 
                        else
                            sudoku[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true; 
    }
    
    bool isValid(vector<vector<char>>& sudoku, int row, int col, char k) {
        for(int i = 0; i < 9; i++) {
            if(sudoku[i][col] == k) return false; 
            if(sudoku[row][i] == k) return false; 
            if(sudoku[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == k) return false;
        }
        return true;
    }
};
