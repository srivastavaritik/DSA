class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);
        vector<int> nodes(n + 1, -1);
        for (auto & d : dislikes)
        {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (nodes[i] != -1) {continue;}
            queue<int> q;
            q.push(i);
            int color = 0;
            while (!q.empty())
            {
                int n = q.size();
                for (int j = 0; j < n; j++)
                {
                    int node = q.front();
                    q.pop();
                    if (nodes[node] != -1 && nodes[node] != color)
                    {
                        return false;
                    }
                    nodes[node] = color;
                    int next_color = !color;
                    for (auto next_node : adj[node])
                    {
                        if (nodes[next_node] == next_color) {continue;}
                        if (nodes[next_node] == -1)
                        {
                            nodes[next_node] = next_color;
                            q.push(next_node);
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                color = ! color;
            }
        }
        return true;
    }
};