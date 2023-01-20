class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> result;
        
        for(int num : nums) {
            auto copy = result;
            for(auto sequence : copy) {
                if(sequence.back() <= num) {
                    sequence.emplace_back(num);
                    result.insert(sequence);
                }
            }
            result.insert({num});
        }
        
        vector<vector<int>> ans;
        for(auto &sequence : result) {
            if(sequence.size() >= 2) ans.push_back(sequence);
        }

        return ans;
    }
};