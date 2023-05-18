class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> a;
        for(int i=0;i<edges.size();i++)
        {
            a.push_back(edges[i][1]);
        }
        map<int,int> m;
        for(int i=0;i<a.size();i++)
        {
            m[a[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
           if(m.find(i)==m.end())
           {
               ans.push_back(i);
           }
        }
        return ans;
    }
};