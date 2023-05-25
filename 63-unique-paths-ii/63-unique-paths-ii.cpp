class Solution {
public:
int fun(int i,int j,vector<vector<int>> & grid,vector<vector<int>> & dp){
    if(i==0&& j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(grid[i][j]==1) return dp[i][j]=0;
        return dp[i][j]=fun(i,j-1,grid,dp)+ fun(i-1,j,grid,dp);
}
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return 0;
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
       return fun(m-1,n-1,grid,dp);
    }
};
