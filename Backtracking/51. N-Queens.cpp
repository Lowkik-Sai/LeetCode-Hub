
   /*
    Time complexity : O(n!) - N is size of the given arr
    Space complexity : O(n^2) - For Visited arr of size N
    Recursion Stack Space : O(N) 
    */

class Solution {
public:
    bool checkSafety(vector<string>& grid,int& n, int row, int col){
        int duprow = row;
        int dupcol = col;
        while(row>=0 && col >= 0) {
            if(grid[row][col] == 'Q') return false;
            row--;
            col--;
        }

        row = duprow;
        col = dupcol;
        while(row<n && col >= 0) {
            if(grid[row][col] == 'Q') return false;
            col--;
            row++;
        }

        return true;
    }

    void placeQueen(vector<string>& grid, int& n, vector<vector<string>>& ans, int col, vector<bool>& rows, vector<bool>& cols){
        if(col >= n){ 
            ans.push_back(grid);
            return ;
        }
        for(int row = 0; row < n; row++){
            if(checkSafety(grid, n, row, col) && !rows[row] && !cols[col]){
                grid[row][col] = 'Q';
                rows[row] = true;
                cols[col] = true;
                placeQueen(grid, n, ans, col+1, rows, cols);
                rows[row] = false;
                cols[col] = false;
                grid[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n);
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                grid[i] += '.';
            }
        }
        vector<bool> rows(n, false);
        vector<bool> cols(n, false);
        placeQueen(grid, n, ans, 0, rows, cols);
        return ans;
    }
};

    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/n-queens/
    */

    

