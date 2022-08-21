class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) 
    {
        // unordered_set<int> s;
        // for(auto it: nums)
        // {
        //     s.insert()
        // }
        int c=0;
        for(int i=0;i<nums.size();i++)
        {
            if(find(nums.begin(), nums.end(), (nums[i]+diff)) != nums.end())
            {
                if(find(nums.begin(), nums.end(), (nums[i]+diff+diff)) != nums.end())
                {
                    c++;
                }
            }
        }
        return c;
    }
};