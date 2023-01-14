class Solution {
public:
    //int cnt=0;
    void dfs(vector<vector<int>> &g,int &ans,int root,vector<int> &vis)
    {
        vis[root]=1;
        //cnt++;
        ans=min(ans,root);
        for(int i=0;i<26;i++)
        {
            if(i==root || g[root][i]==0)continue;
            if(vis[i]==1)continue;
            dfs(g,ans,i,vis);
        }
        return;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<int>> g(26,vector<int> (26,0));
        int n=s1.length();
        for(int i=0;i<n;i++)
        {
            g[s1[i]-'a'][s2[i]-'a']=1;
            g[s2[i]-'a'][s1[i]-'a']=1;
        }
        vector<int> sm(26);
        for(int i=0;i<26;i++)
        {
            int ans=26;
            vector<int> vis(26,0);
            dfs(g,ans,i,vis);
            sm[i]=ans;
        }
        string fs="";
        for(int i=0;i<baseStr.length();i++)
        {
            int index=baseStr[i]-'a';
            fs+=(sm[index]+'a');
        }
        return fs;
    }
};