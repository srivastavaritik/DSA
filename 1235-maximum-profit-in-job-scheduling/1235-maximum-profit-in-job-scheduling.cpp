class Solution {
public:
    int fun(int idx,vector<pair<int,pair<int,int>>>& arr,vector<int>& dp,int n){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        int start=arr[idx].first;
        int end=arr[idx].second.first;
        int profit=arr[idx].second.second;
        pair<int,pair<int,int>> p={end,{0,0}};
        int nextidx=lower_bound(arr.begin(),arr.end(),p)-arr.begin();
        int pick=profit+fun(nextidx,arr,dp,n);
        int notpick=fun(idx+1,arr,dp,n);
        return dp[idx]=max(pick,notpick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<pair<int,pair<int,int>>> arr(n,{0,{0,0}});
        for(int i=0;i<n;i++){
            arr[i]={startTime[i],{endTime[i],profit[i]}};
        }
        vector<int> dp(n+1,-1);
        sort(arr.begin(),arr.end());
        return fun(0,arr,dp,n);
    }
};