class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = INT_MIN, minPrice = INT_MAX;
        for(int i=0;i<prices.size();i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minPrice);
        }
        return maxProfit;
    }
};