class Solution {
public:
    int dp[10001];
    int solve(vector<int>& coins, int amount) {
        if(dp[amount]!=-1) return dp[amount];
        int ans = INT_MAX;
        if(amount == 0) return 0;
        for(auto coin:coins)
        {
            if(amount-coin>=0)
                ans = min(ans+0LL, solve(coins, amount-coin)+1LL);
        }
        return dp[amount]=ans;
    }
    
        int coinChange(vector<int>& coins, int amount) {
            memset(dp, -1, sizeof(dp));
            int ans = solve(coins, amount);
            return ans==INT_MAX ? -1 : ans;
            
        }
};