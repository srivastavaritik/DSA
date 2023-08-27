class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        if(n<=1) return intervals;
        vector<int> temp = intervals[0];
        for(auto it: intervals)
        {
            if(it[0] <= temp[1])
            {
                temp[1] = max(it[1], temp[1]);
            }
            else{
                merged.push_back(temp);
                temp = it;
            }
        }
        merged.push_back(temp);
        return merged;
    }
};