class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1=-1, num2=-1, c1=0, c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==num1) c1++;
            else if(nums[i]==num2) c2++;
            else if(c1==0)
            {
                c1=1;
                num1=nums[i];
            }
            else if(c2==0)
            {
                c2=1;
                num2=nums[i];
            }
            else
            {
                c1--;
                c2--;
            }
        }
        c1=0,c2=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==num1) c1++;
            else if(nums[i]==num2) c2++;
        }
        vector<int> ans;
        int l = nums.size()/3;
        if(c1>l)ans.push_back(num1);
        if(c2>l)ans.push_back(num2);
        return ans;
    }
};