class Solution {
public:
    void solve(vector<int> &vec, int target, int ind, set<vector<int>>&st, vector<int> &temp)
    {
//         //base
//         if(ind==vec.size())
//         {
//             if(target==0)
//             {
//                 st.insert(temp);
//             }
//             return;
//         }
//         //pick
//         if(vec[ind]<=target)
//         {
//             temp.push_back(vec[ind]);
//             solve(vec, target-vec[ind], ind+1, st, temp);
//             //not pick
//             temp.pop_back();
//         }
        
//         while(ind+1<vec.size() and vec[ind]==vec[ind+1]) ind++;
//         solve(vec, target, ind+1, st, temp);
        
        if(target==0)
        {
            st.insert(temp);
            return;
        }
        for(int i=ind;i<vec.size();i++)
        {
            if(i>ind and vec[i]==vec[i-1]) continue;
            if(vec[i]>target) break;
            temp.push_back(vec[i]);
            solve(vec, target-vec[i], i+1, st, temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> st;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0, st, temp);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};