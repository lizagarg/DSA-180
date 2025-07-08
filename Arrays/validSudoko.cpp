class Solution {
    bool isValid(int row, int col, vector<vector<char>>& board) {
        if(board[row][col]=='.') return true;
        for(int i=0; i<9; i++) {
            if(board[row][col]==board[row][i] && col!=i) return false;
            if(board[i][col]==board[row][col] && row!=i) return false;
            int r= 3*(row/3)+i/3;
            int c= 3*(col/3)+i%3;
            if(board[r][c]==board[row][col] && r!=row && c!=col) return false;
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(!isValid(i,j,board)) return false;
            }
        }
        return true;
    }
};

/*
TC: O(9*9*9) for checking each cell in the 9x9 board
SC: O(1) for the isValid function, hence total space complexity is O(1)
This solution is not optimal, as it checks each cell individually.
An optimal solution would use sets to track the numbers in each row, column, and 3x3 subgrid.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for(int r=0; r<9; r++) {
            for(int c=0; c<9; c++) {
                if(board[r][c] == '.') continue;
                char value= board[r][c];
                int boxIndex= 3*(r/3)+c/3;

                if (rows[r].count(value) || cols[c].count(value) || boxes[boxIndex].count(value)) {
                    return false;
                }

                rows[r].insert(value);
                cols[c].insert(value);
                boxes[boxIndex].insert(value);
            }
        }
        return true;
    }
};