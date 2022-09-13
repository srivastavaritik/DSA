class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<=nums.size()-3;i++)
        {
            int j=i+1;
            int k=nums.size()-1;
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            while(j<k)
            {
                int currSum = nums[i];
                currSum+=nums[j];
                currSum+=nums[k];
                if(currSum==0) 
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(nums[j] == nums[j-1] && j < k) j += 1;
                }
                else if(currSum>0)k--;
                else j++;
            }
        }
        return ans;
    }
};