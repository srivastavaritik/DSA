class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sl=s.size(), pl=p.size();
        if(sl<pl)return {};
        
        vector<int> shash(26,0);
        vector<int> phash(26,0);
        
        for(int i=0;i<pl;i++)
        {
            phash[p[i]-'a']++;
            shash[s[i]-'a']++;
        }
        vector<int> ans;
        if(phash==shash)ans.push_back(0);
        
        for(int i=pl;i<sl;i++)
        {
            shash[s[i]-'a']++;
            shash[s[i-pl]-'a']--;
            if(phash==shash)ans.push_back(i-pl+1);
        }
        return ans;
        
    }
};