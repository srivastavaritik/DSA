class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1, mp2;
        bool flag = false;
        for(int i=0; i<s.size();i++)
        {
            mp1[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        for(int i=0;i<s.size();i++)
        {
            if(mp1[s[i]]==t[i] and mp2[t[i]]==s[i]) flag=true;
            else return false;
        }
        return flag;
    }
};