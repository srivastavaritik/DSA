class Solution {
public:
    bool detectCapitalUse(string word) {
        int up=0,lo=0;
        for(int i = 0;i<word.size();i++)
        {
            if(isupper(word[i])) up++;
            else if(islower(word[i])) lo++;
        }
        if(up==word.size() || lo==word.size() || (isupper(word[0]) && lo==word.size()-1))
            return true;
        
        
        return false;
    }
};