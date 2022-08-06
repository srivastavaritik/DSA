class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans=-1;
        sort(nums.begin(), nums.end());
        for(int i =0;i<nums.size()-1;i++)
        {
            if(nums[i+1]-nums[i]>1) {
                ans=nums[i]+1;
                break;
            }
        }
        if(ans==-1 && nums[0]!=0) ans=0;
        if(ans==-1)ans=nums[nums.size()-1]+1;
        return ans;
    }
};