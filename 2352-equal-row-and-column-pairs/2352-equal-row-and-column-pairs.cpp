class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int res=0;
        vector<int> row(n,0);
        vector<int> col(n,0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                row[i] += (grid[i][j]*(j+2))%100000;
                col[i] += (grid[j][i]*(j+2))%100000;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(row[i] == col[j]) res++;
            }
        }
        return res;
    }
};