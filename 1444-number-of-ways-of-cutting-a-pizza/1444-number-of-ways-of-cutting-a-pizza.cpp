class Solution {
public:
int mod = 1e9 + 7;
    int checkHorizontal(int i,int j,int n,int m,vector<string> &pizza)
    {
        for(int x=i; x<n; x++)
        {
            for(int y=j; y<m; y++)
            {
                if(pizza[x][y]=='A') return 1;
            }
        }
        return 0;
    }
    int checkVertical(int i,int j,int n,int m,vector<string> &pizza)
    {
        for(int x=i; x<n; x++)
        {
            for(int y=j; y<m; y++)
            {
                if(pizza[x][y]=='A') return true;
            }
        }
        return false;
    }
    long long int solve(int i,int j,int k,int n,int m,vector<string> &pizza,vector<vector<vector<int>>> &dp)
    {
        if(k==0)
        {
            for(int x=i; x<n; x++)
            {
                for(int y=j; y<m; y++)
                {
                    if(pizza[x][y]=='A') return true;
                    
                }
            }
            return false;
        }
        if(i>=n || j>=m) return 0;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        long long int count=0;
        for(int ni=i+1; ni<n; ni++)
        {
            if(checkHorizontal(i,j,ni,m,pizza)) count += solve(ni,j,k-1,n,m,pizza,dp);
            
        }

        for(int nj=j+1; nj<m; nj++)
        {
            if(checkHorizontal(i,j,n,nj,pizza))  count += solve(i,nj,k-1,n,m,pizza,dp);
            
         }
        
        return dp[i][j][k]=(count%mod);
    }

    int ways(vector<string>& pizza, int k) {
        int n=pizza.size(), m=pizza[0].size(); 
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (m,vector<int> (k,-1)));
        return solve(0,0,k-1,n,m,pizza,dp);
    }
};