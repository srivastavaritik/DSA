class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<int,int> rn,mg;
        for(auto it: ransomNote)
        {
            rn[it]++;
        }
        for(auto it: magazine)
        {
            mg[it]++;
        }
        for(int i=0;i<ransomNote.size();i++)
        {
            if(mg[ransomNote[i]] < rn[ransomNote[i]]) return false;
        }
        return true;
    }
};