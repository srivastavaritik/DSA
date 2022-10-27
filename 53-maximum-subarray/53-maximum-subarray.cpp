class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curmax=0, maxsum=nums[0];
        for(int i=0;i<nums.size();i++){
            curmax+=nums[i];
            if(curmax>maxsum) maxsum=curmax;
            if(curmax < 0) curmax=0;
            
        }
        return maxsum;
    }
};