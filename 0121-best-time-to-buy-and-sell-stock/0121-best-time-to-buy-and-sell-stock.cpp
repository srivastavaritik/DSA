class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), mini=INT_MAX, profit=0;
        for(int i=0;i<n;i++)
        {
            profit=max(profit, prices[i]-mini);
            mini=min(mini, prices[i]);
        }
        return profit;
    }
};