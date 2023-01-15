class UnionFind 
{
    private:
        vector<int> parent, rank;

    public:
        UnionFind(int size) 
        {
            parent.resize(size);
            rank.resize(size, 0);
            for (int i = 0; i < size; i++) {
                parent[i] = i;
            }
        }
        int find(int x) 
        {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        void union_set(int x, int y) 
        {
            int xset = find(x), yset = find(y);
            if (xset == yset) 
            {
                return;
            } else if (rank[xset] < rank[yset]) 
            {
                parent[xset] = yset;
            } else if (rank[xset] > rank[yset]) 
            {
                parent[yset] = xset;
            } else 
            {
                parent[yset] = xset;
                rank[xset]++;
            }
        }
};
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) 
    {
        int n = vals.size();
        vector<vector<int>>adj(n);

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }   

        map<int,vector<int>>value;
        for(int i=0;i<n;i++)
        {
            value[vals[i]].push_back(i);
        }    

        UnionFind dsu(n);
        int ans=0;

        for(auto& [v,no]:value)
        {
            for(int node:no)
            {
                for(int neighobur:adj[node])
                {
                    if(vals[node] >= vals[neighobur])
                    {
                        dsu.union_set(node,neighobur);
                    }
                }
            }

            unordered_map<int,int>grp;

            for(int u:no)
            {
                grp[dsu.find(u)]++;
            }

            for(auto& [_,size]:grp)
            {
                ans += (size * (size+1)/2);
            }
        } 

        return ans;

    }
};