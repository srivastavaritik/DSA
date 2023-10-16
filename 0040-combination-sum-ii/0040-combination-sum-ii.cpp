class Solution {
public:
    void solve(int ind, vector<int> &vec, int target, set<vector<int>>&st, vector<int>&temp)
    {
        if(ind==vec.size())
        {
            if(target==0)
            {
                st.insert(temp);
            }
            return;
        }
        if(vec[ind]<=target)
        {
            temp.push_back(vec[ind]);
            solve(ind+1, vec, target-vec[ind], st, temp);
            temp.pop_back();
        }
        while(ind<vec.size()-1 and vec[ind]==vec[ind+1]) ind++;
        solve(ind+1, vec, target, st, temp);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>>st;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target, st, temp);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};