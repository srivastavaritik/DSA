class Solution {
public:
int sumSubarrayMins(vector<int>& a) {
	
        int i,n=a.size();
        int m=1e9+7;
        vector<long> l(n),r(n);
        stack<int> s;
        long ans=0;
        
        for(i=n-1;i>=0;i--)
        {
            while(!s.empty() && a[s.top()]>=a[i])
            {
                l[s.top()]=i;
                s.pop();
            }
            
            s.push(i);
        }
        
        while(!s.empty())
        {
            l[s.top()]=-1;
            s.pop();
        }
        
        for(i=0;i<n;i++)
        {
            while(!s.empty() && a[s.top()]>a[i])
            {
                r[s.top()]=i;
                s.pop();
            }
            
            s.push(i);
        }
        
        while(!s.empty())
        {
            r[s.top()]=n;
            s.pop();
        }
        
        for(i=0;i<n;i++)
        {
            ans+=((i-l[i])*(r[i]-i)*a[i])%m;
            ans%=m;
        }
        
        return ans;
    }
};