class Solution {
public:
        int minTime(int n, vector<vector<int>>& edges, vector<bool>& apple) {
        vector<vector<int>> G(n);
        for(vector<int> &e:edges){
            G[e[0]].push_back(e[1]);
            G[e[1]].push_back(e[0]); 
        }
        int res=  dfs(G,0,-1,apple);
        return res>=2?res-2:res;
    }
    
    int dfs(vector<vector<int>> &G,int node,int par,vector<bool>& apple){
        int res = 0;
        for(auto &ch : G[node]){
            if(ch==par) continue;
            res+=dfs(G,ch,node,apple);
        }
        if(apple[node]==true or res>0){
            res+=2;
            return res;
        }
        return 0;
    }
};