
    /*
    Time complexity : O(m * n)
    Space complexity : O(m * n) - Recursion stack space
    */


class Solution {
public:

    bool checkSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int& m, int& n, int& mark){
        if(i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] != 1) return true; 
        if(grid1[i][j] != 1) return false;
        grid2[i][j] = mark;
        bool left = checkSubIsland(grid1, grid2, i, j-1, m, n, mark);
        bool right = checkSubIsland(grid1, grid2, i, j+1, m, n, mark);
        bool up = checkSubIsland(grid1, grid2, i-1, j, m, n, mark);
        bool down = checkSubIsland(grid1, grid2, i+1, j, m, n, mark);
        return left & right & up & down;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int count = 0;
        int m = grid2.size();
        int n = grid2[0].size();
        int mark = 2;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid2[i][j] == 1){
                    if(checkSubIsland(grid1, grid2, i, j, m, n, mark)) count += 1;
                    mark += 1;
                }
            }
        }
        return count;
    }
};


    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/count-sub-islands/?envType=daily-question&envId=2024-08-28
    */

    