class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int l = arr.size();
        int ans=0;
        if(l<3)return ans;
        for(int i=1;i<l-1;)
        {
            if(arr[i]>arr[i-1] and arr[i]>arr[i+1])
            {
                int count=1;
                int j=i;
                while(j>=1 and arr[j]>arr[j-1])
                {
                    count++;
                    j--;
                }
                while(i<l-1 and arr[i]>arr[i+1])
                {
                    count++;
                    i++;
                }
                ans=max(ans,count);
            }
            else i++;
        }
        return ans;
    }
};