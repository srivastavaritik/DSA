class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n = mat.size(), m = mat[0].size();
        if(m==0)return 0;
        int low = 0, high = m*n -1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            int r = mid/m, c=mid%m;
            if(mat[r][c]==t) return 1;
            else if(mat[r][c]<t) low=mid+1;
            else high=mid-1;
        }
        return 0;
    }
};