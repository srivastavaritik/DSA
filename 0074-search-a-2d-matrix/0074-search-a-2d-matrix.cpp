class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n =  matrix.size(), m = matrix[0].size();
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
        // int i = 0, j=n-1;
        // while(i<m and j>=0)
        // {
        //     if(matrix[i][j]==target) return 1;
        //     else if(matrix[i][j] < target) i++;
        //     else j--;
        // }
        // return 0;
        
        
        //BEST
        int l=0, h=(m*n)-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(matrix[mid/m][mid%m]==target) return 1;
            else if(matrix[mid/m][mid%m]<target) l=mid+1;
            else h=mid-1;
        }
        return 0;
        
    }
};