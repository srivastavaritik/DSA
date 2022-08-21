class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int n=accounts.size();
        int m=accounts[0].size();
        int maxx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int s=0; 
            for(int j=0;j<m;j++)
            {
                s+=accounts[i][j];
            }
            maxx = max(maxx, s);
        }
        return maxx;
    }
};