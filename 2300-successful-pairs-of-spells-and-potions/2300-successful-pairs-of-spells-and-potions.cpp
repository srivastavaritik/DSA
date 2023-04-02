class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> ans;
        for(int i=0;i<spells.size();i++)
        {
            int sum=0;
            if(spells[i]>=success) sum=potions.size();
            else
            {
            
                long long x=ceil((double)success/spells[i]);
              auto low1 = lower_bound(potions.begin(), potions.end(),x);
                 
                 sum=potions.size()-(low1 - potions.begin());
              
            }
            ans.push_back(sum);
        }
        return ans;
    }
};