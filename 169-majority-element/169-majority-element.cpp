class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //MOST VOTING ALGORITHM
        int c=0, ele=0;
        for(int i=0;i<nums.size();i++)
        {
            if(c==0) ele = nums[i];
            if(nums[i]==ele) c++;
            else c--;
        }
        return ele;
    }
};