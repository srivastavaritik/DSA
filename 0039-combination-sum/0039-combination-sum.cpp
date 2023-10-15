class Solution {
public:
    void solve(vector<int> &vec, int target, vector<vector<int>>& ans, vector<int> &temp, int ind)
    {
        //base
        if(ind==vec.size())
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return;
        }
        //not pick
        if(vec[ind]<=target)
        {
            temp.push_back(vec[ind]);
            solve(vec, target-vec[ind], ans, temp, ind);
            temp.pop_back();
        }
        //pick
        solve(vec, target, ans, temp, ind+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates, target, ans, temp, 0);
        return ans;
    }
};