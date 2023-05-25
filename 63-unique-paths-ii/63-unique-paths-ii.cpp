class Solution {
public:
int fun(int i,int j,vector<vector<int>> & grid,vector<vector<int>> & dp){
    if(i==0&& j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(grid[i][j]==1) return dp[i][j]=0;
        return dp[i][j]=fun(i,j-1,grid,dp)+ fun(i-1,j,grid,dp);
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]) return 0;
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
       return fun(obstacleGrid.size()-1,obstacleGrid[0].size()-1,obstacleGrid,dp);
    }
};
