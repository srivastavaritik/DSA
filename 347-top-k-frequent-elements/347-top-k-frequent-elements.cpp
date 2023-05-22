class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int, int> b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i : nums) {
            mp[i]++;
        }
        vector<pair<int,int>> v;
        vector<int> res;
        for(const auto& p : mp) {
            v.push_back({p.first,p.second});
        }
        sort(v.begin(), v.end(), cmp);
        for(int i=0; i<k; i++) {
            res.push_back(v[i].first);
        }
        return res;
    }
};