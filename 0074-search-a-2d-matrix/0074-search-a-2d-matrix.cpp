class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m =  matrix.size(), n = matrix[0].size();
        // BRUTE FORCE
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(matrix[i][j]==target) return 1;
        //     }
        // }
        // return 0;
        
        // OPTIMAL
        int i = 0, j=n-1;
        while(i<m and j>=0)
        {
            if(matrix[i][j]==target) return 1;
            else if(matrix[i][j] < target) i++;
            else j--;
        }
        return 0;
        
    }
};