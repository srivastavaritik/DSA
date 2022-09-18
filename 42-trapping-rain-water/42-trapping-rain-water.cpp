class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n<=2)return 0;
        vector<int> left(n,0),right(n,0);
        left[0]=height[0], right[n-1]=height[n-1];
        for(int i=1; i<n;i++){
            left[i]=max(left[i-1], height[i]);
            right[n-i-1]=max(right[n-i],height[n-i-1]);
        }
        int s=0;
        for(int i=1;i<n;i++)
        {
            s+=abs(min(left[i],right[i])-height[i]);
        }
        return s;
    }
};