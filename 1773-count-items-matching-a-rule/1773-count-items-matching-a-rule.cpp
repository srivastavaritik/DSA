class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) 
    {
        int k;
        if(ruleKey == "type") k=0;
        else if(ruleKey == "color") k=1;
        else k=2;
        int c=0;
        for(int i=0;i<items.size();i++)
        {
            if(items[i][k] == ruleValue)c++;
        }
        return c;
    }
};