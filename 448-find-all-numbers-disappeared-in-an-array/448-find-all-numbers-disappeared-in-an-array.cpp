class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> s;
        int t=1;
        for(auto it:nums)
        {
            s.insert(it);
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(s.find(i)==s.end())ans.push_back(i);
        }
        return ans;
    }
};