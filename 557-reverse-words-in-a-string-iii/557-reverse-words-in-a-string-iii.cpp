class Solution {
public:
    string reverseWords(string s) {
        int i=0,j=0;
        while(j<=s.length()){
            if(s[j]==' '||j==s.length()){
                reverse(s.begin()+i,s.begin()+j);
                i=j+1;
                j++;
            }
            else{
                j++;
            }
        }
        return s;
    }
};