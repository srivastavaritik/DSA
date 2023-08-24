class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cSum=0, mSum=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            cSum+=nums[i];
            mSum = max(mSum, cSum);
            if(cSum<0) cSum=0;
        }
        return mSum;
    }
};