class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size(), ans = 0;
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (!vis[i][j]) {
                    vis[i][j] = true;
                    if (grid[i][j] == 0) {
                        int flag = 0;
                        q.push({i, j});
                        ans++;
                        while (!q.empty()) {
                            auto ele = q.front(); q.pop();
                            int m = ele.first, n = ele.second;
                            if (m == 0 || m == row - 1 || n == 0 || n == col - 1) {
                                flag = 1;
                            }
                            vis[m][n] = true;
                            // left
                            if (n > 0 && grid[m][n - 1] == 0 && !vis[m][n - 1]) {
                                q.push({m, n - 1});
                            }
                            // right
                            if (n < col - 1 && grid[m][n + 1] == 0 && !vis[m][n + 1]) {
                                q.push({m, n + 1});
                            }
                            // up
                            if (m > 0 && grid[m - 1][n] == 0 && !vis[m - 1][n]) {
                                q.push({m - 1, n});
                            }
                            // down
                            if (m < row - 1 && grid[m + 1][n] == 0 && !vis[m + 1][n]) {
                                q.push({m + 1, n});
                            }
                        }
                        ans -= flag;
                    }
                }
            }
        }
        return ans;
    }
};