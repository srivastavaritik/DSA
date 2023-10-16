class Solution {
public:
    void solve(int ind, vector<int>&vec, int target, vector<vector<int>>&ans, vector<int> &temp)
    {
        if(ind==vec.size())
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return;
        }
        if(vec[ind]<=target)
        {
            temp.push_back(vec[ind]);
            solve(ind, vec, target-vec[ind], ans, temp);
            temp.pop_back();
        }
        solve(ind+1, vec, target, ans, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates, target, ans, temp);
        return ans;
    }
};