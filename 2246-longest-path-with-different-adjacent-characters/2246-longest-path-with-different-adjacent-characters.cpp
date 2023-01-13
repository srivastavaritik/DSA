class Solution {
public:
    int ans=1;
    int cal(int u,string& s,vector<int> graph[])
    {
        if(graph[u].empty())
            return 1;
        int cnt1=0,cnt2=0;
        for(auto &v:graph[u])
        {
            int curr=cal(v,s,graph);
            ans=max(ans,curr);
            if(s[u]!=s[v])
            {
                if(curr>cnt1)
                {
                    cnt2=cnt1;
                    cnt1=curr;
                }
                else if(curr>cnt2)
                {
                    cnt2=curr;
                }
            }
        }
        ans=max(ans,1+cnt1+cnt2);
        return cnt1+1;
    }
    int longestPath(vector<int>& parent, string s) {
        int n=parent.size();
        vector<int> graph[n];
        for(int i=1;i<n;i++)
        {
            graph[parent[i]].push_back(i);
        }
        cal(0,s,graph);
        return ans;
    }
};