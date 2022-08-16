class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++)
        {
            mpp[s[i]]++;
        }
        char tch;

        for(int i=0;i<s.size();i++)
        {
            if(mpp[s[i]]==1)return i;
        }
        return -1;
    }
};