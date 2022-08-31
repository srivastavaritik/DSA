class Solution {
public:
     int m, n;
    void helper(vector<vector<int>> &heights, vector<vector<bool>> &visited, int i, int j) {
        if(visited[i][j]) return;
        visited[i][j] = true;
        if(i > 0 && !visited[i-1][j] && heights[i][j] <= heights[i-1][j]) {
            helper(heights, visited, i-1, j);
        }
        if(i+1 < m && !visited[i+1][j] && heights[i][j] <= heights[i+1][j]) {
            helper(heights, visited, i+1, j);
        }
        if(j > 0 && !visited[i][j-1] && heights[i][j] <= heights[i][j-1]) {
            helper(heights, visited, i, j-1);
        }
        if(j+1 < n && !visited[i][j+1] && heights[i][j] <= heights[i][j+1]) {
            helper(heights, visited, i, j+1);
        }
        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int i = 0; i < n; i++) { 
            helper(heights, pacific, 0, i);
            helper(heights, atlantic, m-1, i);
        }
        for(int i = 0; i < m; i++) {
            helper(heights, pacific, i, 0);
            helper(heights, atlantic, i, n-1);
        }
        vector<vector<int>> ans;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};