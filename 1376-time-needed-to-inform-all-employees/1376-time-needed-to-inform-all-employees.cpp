class Solution {
public:
    int dfs(int node, vector<vector<int>> &adj, vector<int>& informTime){
        int ans = 0;

        for (auto v: adj[node]){
            ans = max(ans, informTime[node] + dfs(v, adj, informTime));
        }

        return ans;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i=0; i<n; i++){
            if (i!=headID){
                adj[manager[i]].push_back(i);
            }
        }

        return dfs(headID, adj, informTime);

    }
};