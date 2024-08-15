
    /*
    Time Complexity: O(m * n * log(m * n))
    Space Complexity: O(m * n)
    */

class Solution {
public:
    int getSafenessFactor(vector<vector<int>>& grid, int i, int j, map<int, vector<pair<int, int>>>& mp) {
        int minSafe = INT_MAX;
        for (auto [x, y] : mp[1]) {
            minSafe = min(minSafe, abs(x - i) + abs(y - j));
        }
        return minSafe;
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        // map<int, vector<pair<int, int>>> mp;

        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (grid[i][j] == 1) mp[1].push_back({i, j});
        //     }
        // }

        // vector<vector<int>> safe(m, vector<int>(n, 0));
        // for (int i = 0; i < m; i++) {
        //     for (int j = 0; j < n; j++) {
        //         safe[i][j] = getSafenessFactor(grid, i, j, mp);
        //     }
        // }

        vector<vector<int>> safe(n, vector<int> (m, 1e9));
        queue<pair<int, int>> fifo;

        for(int i = 0; i <= n - 1; i++){
            for(int j = 0; j <= m - 1; j++){
                if(grid[i][j] == 1){
                    safe[i][j] = 0;
                    fifo.push({i, j});
                }
            }
        }

        while(!fifo.empty()){
            auto [i, j] = fifo.front();
            fifo.pop();

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for(auto dir : directions){
                int newX = i + dir.first;
                int newY = j + dir.second;

                if(newX >= 0 && newY >= 0 && newX < n && newY < m && safe[newX][newY] > 1 + safe[i][j]){
                    safe[newX][newY] = 1 + safe[i][j];
                    fifo.push({newX, newY});
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> q;
        q.push({safe[0][0], {0, 0}});
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[0][0] = true;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            auto top = q.top();
            int safety = top.first;
            int x = top.second.first;
            int y = top.second.second;
            q.pop();

            if (x == m - 1 && y == n - 1) return safety;

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({min(safety, safe[nx][ny]), {nx, ny}});
                }
            }
        }

        return 0;
    }
    
};

    /*
    Author : Lowkik-Sai
    Question Link : https://leetcode.com/problems/find-the-safest-path-in-a-grid/
    */
