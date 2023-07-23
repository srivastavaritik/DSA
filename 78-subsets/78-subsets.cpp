class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int> vec, int ind, vector<int> nums)
    {
        if(ind>=nums.size())
        {
            ans.push_back(vec);
            return;
        }
        vec.push_back(nums[ind]);
        solve(ans, vec, ind+1, nums);
        vec.pop_back();
        solve(ans, vec, ind+1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        solve(ans, vec, 0, nums);
        return ans;
    }
};