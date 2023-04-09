class Solution {
public:
    bool checkCycle(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &pathVis) {
        vis[node] = true;
        pathVis[node] = true;
        
        bool ans = false;
        for(auto &iter : adj[node]) {
            if(pathVis[iter]) return true;
            if(!vis[iter]) {
                ans |= checkCycle(iter, adj, vis, pathVis);
                if(ans) return true;
            }
            else if(iter == node) return true;
        }
        
        pathVis[node] = false;
        
        return ans;
    }
    
    int* dfs(int node, vector<int> adj[], string &colors, vector<bool> &vis, int dp[][26]) {
    
        if(vis[node]) return dp[node];

        int* Curr;
        for(auto &nigg : adj[node]) {
 
            Curr = dfs(nigg, adj, colors, vis, dp);
            for(int i = 0; i < 26; i++) 
                dp[node][i] = max(Curr[i], dp[node][i]);
        }
        dp[node][colors[node] - 'a']++;

        
        vis[node] = true;
        
        return dp[node];
    }
    
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
        int n = colors.size();
        vector<int> adjList[n];
        
        vector<int> inDegrees(n, 0);
        
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adjList[u].push_back(v);
            inDegrees[v]++;
        }
        
        vector<bool> vis(n, false), pathVis(n, false);
        
        bool hasCycle = false;
        for(int i = 0; i < n; i++) 
            if(!vis[i]) hasCycle |= checkCycle(i, adjList, vis, pathVis);
        
        if(hasCycle) return -1;
        int ans = 0;
        
        vis.assign(n, false);

        int dp[n][26];
        memset(dp, 0, sizeof dp);
        
        for(int i = 0; i < n; i++) {
            if(!inDegrees[i]) {
                int *freqs = dfs(i, adjList, colors, vis, dp);
                for(int i = 0; i < 26; i++) ans = max(ans, freqs[i]);
            }
        }
        
        return ans;
    }
};