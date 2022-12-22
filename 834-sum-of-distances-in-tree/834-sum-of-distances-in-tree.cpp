class Solution {
public:
    int dfs1(int node ,vector<int> &visited ,vector<vector<int>> &adj  ,vector<int> &childs ,vector<int> &res) // finding number of nodes in subtree i  . 
    {    
        visited[node] = 1 ;
        int no_childs = 0 , sum_distance_subtreei = 0 ; 
        for( auto x : adj[node])
        {
            if(!visited[x])
            {
                no_childs += dfs1(x,visited,adj,childs,res);
                sum_distance_subtreei += res[x];
            }
        }
        childs[node]=no_childs+1;
        res[node] = no_childs+sum_distance_subtreei;
        return childs[node];
    }
    void dfs2(int node , vector<int> &visited , vector<vector<int>> &adj , vector<int> &childs , vector<int> &res )
    { 
        visited[node] = 1;
        int N = adj.size();
        for( auto c : adj[node])
        {   
            if(!visited[c])
            { 
             
                res[c] = res[node]-childs[c]+N-childs[c];
            
                dfs2(c,visited,adj,childs,res);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e : edges )
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> childs(n,0) , res(n,0),visited(n,0);
        dfs1(0,visited,adj,childs,res);
        for( int i = 0 ; i < n ; ++i )
        visited[i] = 0 ;
        
        vector<int> visited2(n,0);
        dfs2(0,visited2,adj,childs,res);
        
        
        return res;
    }
};