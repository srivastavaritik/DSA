class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> vec;
        vec.push_back(0);
        int curr =0;
        for(int i=0;i<gain.size();i++)
        {
            curr = curr + gain[i];
            vec.push_back(curr);
        }
        int ans = 0;
        for(auto it:vec)
        {
            ans = max(ans, it);
        }
        return ans;
    }
};