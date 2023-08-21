class Solution {
public:
    bool isAnagram(string s1, string s2) {
    if(s1.size() != s2.size()) return false;
    unordered_map<char, int> mpp;
    for (auto it : s1)
        mpp[it]++;
    for (auto it : s2)
    {
        mpp[it]--;
        if(mpp[it]==0) mpp.erase(it);
    }
    return mpp.size()==0;
    }
};