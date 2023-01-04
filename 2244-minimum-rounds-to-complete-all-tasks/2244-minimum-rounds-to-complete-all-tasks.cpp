class Solution {
public:
         int count_effrounds(int freq,int c2)
    {
        int res;
        if(freq<2)
            return 0;
        else
        {
            if(freq%3==0)
                return freq/3;
            else
            {
                c2=1+count_effrounds(freq-2,c2);
                return res;    
            }
        }
    }
    int minimumRounds(vector<int>& tasks) 
    {
        int n=tasks.size();
        int ans=0;
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[tasks[i]]++;
        }
        for(auto x:mp)
        {
            if(x.second==1)
                return -1;
            else 
            {
                int c2=0;
                ans+=count_effrounds(x.second,c2);    
            }
        }
        return ans;    
    }
    
};