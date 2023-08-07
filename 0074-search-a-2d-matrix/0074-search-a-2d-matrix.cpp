class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int i=0, j=(m*n)-1;
        while(i<=j)
        {
            int mid = (i+j)/2;
            if(matrix[mid/m][mid%m]==target) return 1;
            else if(matrix[mid/m][mid%m]<target) i=mid+1;
            else j=mid-1;
        }
        return 0;
    }
};