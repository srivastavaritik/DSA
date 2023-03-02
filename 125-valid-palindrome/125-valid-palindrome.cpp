class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        string str="";
        for(int i=0;i<n;i++)
        {
            if(isalnum(s[i])==false)continue;
            str.push_back(tolower(s[i]));
        }
        s=str;
        reverse(str.begin(), str.end());
        return str==s;
    }
};