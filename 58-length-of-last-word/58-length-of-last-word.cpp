class Solution {
public:
    int lengthOfLastWord(string s) {
        // if(s.size()<=1)return s.size();
        // int l = s.size()-1;
        // while(s[l]==' ' and l>=0)l--;
        // int f = 0;
        // while(s[l]!=' ' and l>=0)
        // {
        //     f++;
        //     l--;
        // }
        // return f;
        int len = 0, tail = s.length() - 1;
        while (tail >= 0 && s[tail] == ' ') tail--;
        while (tail >= 0 && s[tail] != ' ') {
            len++;
            tail--;
        }
        return len;
    }
};