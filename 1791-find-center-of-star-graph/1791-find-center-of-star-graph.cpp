class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mpp;
        for(auto it:edges)
        {
            mpp[it[0]]++;
            mpp[it[1]]++;
        }
        int n = edges.size();
        for(auto it:mpp)
        {
            if(it.second == n) return it.first;
        }
        return -1;
    }
};