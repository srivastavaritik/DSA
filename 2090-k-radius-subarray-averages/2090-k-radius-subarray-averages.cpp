class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        if(n<=2*k){
            res.resize(n,-1);
            return res;
        }
        for(int i=0;i<k;i++){
            res.push_back(-1);
        }
        long long sum = 0;      // To avoid integer overflow.
        for(int i=0;i<=2*k;i++){
                sum+=nums[i];
        }
        // cout<<sum<<" ";
        int ind = 0;
        int div = (2*k)+1;  
        for(int i=k+1;i<n-k;i++){
            res.push_back(sum/div);
            sum-=nums[ind++];   //removing first element
            sum+=nums[i+k];     // adding last element
        }
        res.push_back(sum/div);
        for(int i=n-k;i<n;i++){
            res.push_back(-1);
        }
        return res;
    }
};