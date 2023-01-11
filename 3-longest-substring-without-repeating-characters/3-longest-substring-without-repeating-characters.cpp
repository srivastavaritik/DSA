class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")return 0;
        int len=INT_MIN;
        set<char> st;
        int l= 0;
        for(int r=0;r<s.size();r++)
        {
            if(st.find(s[r]) != st.end())
            {
                while(l<r and st.find(s[r]) != st.end())
                {
                    st.erase(s[l]);
                    l++;
                }
            }
           
                st.insert(s[r]);
                len=max(len, r-l+1);
                   }
        return len;
    }
};
