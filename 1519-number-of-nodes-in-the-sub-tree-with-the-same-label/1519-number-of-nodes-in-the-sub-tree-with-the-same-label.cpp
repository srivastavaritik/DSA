class Solution 
{
    unordered_map<int, vector<int>> g;
    vector<bool> visited;
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) 
    {
        for (auto& e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        vector<int> ans(n);
        vector<int> cnt(26);
        visited.resize(n);
        dfs(ans, cnt, labels, 0);

        return ans;
    }

    void dfs(vector<int>& ans, vector<int>& cnt, string& label, int cur)
    {
        vector<int> children(26);
        visited[cur] = 1;
        for (auto& next : g[cur])
        {
            if (!visited[next])
            {
                visited[next] = 1;
                dfs(ans, children, label, next);
            }
        }

        children[label[cur] - 'a'] += 1;
        ans[cur] = children[label[cur] - 'a'];

        for (int i = 0; i < 26; ++i)
        {
            cnt[i] += children[i];
        }
    }
};