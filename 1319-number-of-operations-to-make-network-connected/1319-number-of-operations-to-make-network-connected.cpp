class Solution {
public:
    int extra=0;
    int findparent(vector<int> &par,int u)
    {
        if(u==par[u])
        {
            return u;
        }
        return par[u]=findparent(par,par[u]);
    }
    void make_union(vector<int> &par,int u,int v)
    {
        int pu=findparent(par,u);
        int pv=findparent(par,v);
        par[pu]=pv;
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        int m=connections.size();
        vector<int> par(n);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            par[i]=i;
        }
        for(auto v:connections)
        {
            int pu=findparent(par,v[0]);
            int pv=findparent(par,v[1]);
            if(pu!=pv)
            {
                make_union(par,v[0],v[1]);
            }
            else
                extra++;
        }
        for(int i=0;i<n;i++)
        {
            if(par[i]==i)
                cnt++;
        }
        cnt--;// for extra count of parent in main connection
        return cnt>extra?-1:cnt;
        
    }
};