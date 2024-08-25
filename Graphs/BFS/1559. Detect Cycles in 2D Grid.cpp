
    /*
    Time complexity: O(m * n)
    Space complexity: O(m * n)
    */
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j]) {
                    queue<pair<pair<int, int>, pair<int, int>>> q;
                    q.push({{i, j}, {-1, -1}});
                    vis[i][j] = 1;
                    
                    while (!q.empty()) {
                        auto curr = q.front();
                        q.pop();
                        int x = curr.first.first;
                        int y = curr.first.second;
                        int prevX = curr.second.first;
                        int prevY = curr.second.second;
                        
                        for (auto [dx, dy] : directions) {
                            int newX = x + dx;
                            int newY = y + dy;
                            if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == grid[x][y]) {
                                if (vis[newX][newY]) {
                                    if (!(newX == prevX && newY == prevY)) return true;
                                } else {
                                    vis[newX][newY] = 1;
                                    q.push({{newX, newY}, {x, y}});
                                }
                            }
                        }
                    }
                }
            }
        }
        return false;
    }
};

    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/detect-cycles-in-2d-grid/
    */
