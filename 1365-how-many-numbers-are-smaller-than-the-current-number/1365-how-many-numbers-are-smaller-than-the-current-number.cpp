class Solution {
public:
    int freq(vector<int>&nums, int n)
    {
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<n)c++;
        }
        return c;
    }
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            ans.push_back(freq(nums, nums[i]));
        }
        return ans;
    }
};