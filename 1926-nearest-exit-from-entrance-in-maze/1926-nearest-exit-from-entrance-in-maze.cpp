class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int path  = INT_MAX;
        int m = maze.size(), n = maze[0].size();
        int adj_row[] = {0, 1, 0, -1};
        int adj_col[] = {1, 0, -1, 0};
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[entrance[0]][entrance[1]] = true;
        
        while(!q.empty()){
            pair<int, int> cell = q.front().first;
            int len = q.front().second;
            q.pop();
            
            if((cell.first != entrance[0] || cell.second != entrance[1]) && 
               ((cell.first == m-1 || cell.first == 0) || (cell.second == n-1 || cell.second == 0))){
                path = min(path, len);
            }
            
            for(int i = 0; i < 4; i++){
                int nrow = adj_row[i] + cell.first;
                int ncol = adj_col[i] + cell.second;
                
                if((nrow >= 0 && nrow < m) && (ncol >= 0 && ncol < n) &&
                  (vis[nrow][ncol] == false) && (maze[nrow][ncol] != '+')){
                    q.push({{nrow, ncol}, len+1});
                    vis[nrow][ncol] = true;
                }
            }
        }
        return path == INT_MAX? -1 : path;
    }
};