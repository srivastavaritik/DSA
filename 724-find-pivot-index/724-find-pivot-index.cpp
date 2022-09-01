class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum1=0, sum2=0,sum=accumulate(nums.begin(), nums.end(),0);
        sum2=sum;
        for(int i=0;i<nums.size();i++)
        {
            sum2-=nums[i];
            if(sum1==sum2)return i;
            sum1+=nums[i];
        }
        return -1;
    }
};