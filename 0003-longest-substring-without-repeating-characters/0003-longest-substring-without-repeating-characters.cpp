class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mpp;
        int len =0, left=0, right=0, n=s.size();
        while(right<n)
        {
            if(mpp.find(s[right]) != mpp.end())
            {
                left = max(left, mpp[s[right]]+1);
            }
            mpp[s[right]] = right;
            len = max(len, right-left+1);
            right++;
        }
        return len;
    }
};