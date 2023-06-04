class Solution {
public:
 void bfs(queue<int>q,vector<int>adj[],vector<int> &vis)
    {
        while(!q.empty())
        {
            int ind = q.front();
            q.pop();

            if(vis[ind])
            continue;
            vis[ind] = 1;

            for(auto x: adj[ind])
            {
                if(vis[x] == 0)
                {
                    q.push(x);
                    //vis[x]=1;
                }
            }
        }
        
    }
public:
    int findCircleNum(vector<vector<int>>& isC) {
        int n = isC.size();

        vector<int>adj[n];
        vector<int>vis(n,0);
        queue<int>q;
        //creating a adj list
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<isC[j].size();i++)
            {
                if(isC[j][i]== 1 && i!=j )
                adj[j].push_back(i);
            }
        }
        int cnt=0;

        for(int i=0;i<n;i++)
        {
            //if its not visited, then it must be a new province
            if(!vis[i])
            {
                cout<<i<<"\n";
                q.push(i);
                //Will travel all the nodes in this province
                bfs(q,adj,vis);
                cnt++;
            }
        }
        return cnt;
        
    }
};