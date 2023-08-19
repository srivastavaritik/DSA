class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
        int i=0, l1=word1.size(), l2=word2.size();
        while(i<l1 and i<l2)
        {
            res+=word1[i];
            res+=word2[i];
            i++;
        }
        if(l1>l2)
        {
            while(i<l1)
            {
                res+=word1[i];
                i++;
            }
        }
        else if(l1<l2){
            while(i<l2)
            {
                res+=word2[i];
                i++;
            }
        }
        return res;
    }
};