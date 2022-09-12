class Solution {
public:
    int characterReplacement(string s, int k) {
            unordered_map<char,int> mp;
        int i=0,j=0,maxfreq=0,ans=INT_MIN;
        
        while(j<s.length())
        {
            mp[s[j]]++;      // insert the character into map
            maxfreq=max(maxfreq,mp[s[j]]); // find character with maximum frequency
            if((j-i+1)-maxfreq>k) //if character with min frequency > k 
            {
               mp[s[i]]--;
                i++;
            }
            ans=max(ans,j-i+1);  // finding the largest window
            j++;
            
            
        }
        return ans;
    }
};