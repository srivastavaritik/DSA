class Solution {
public:
    void merge(int l, int r, vector<int> &nums)
    {
        int i = l;
        int m = (l+r)/2;
        int j = m+1;
        vector<int> sorted;
        while(i<=m and j<=r)
        {
            if(nums[i]<nums[j])
            {
                sorted.push_back(nums[i]);
                i++;
            }
            else
            {
                sorted.push_back(nums[j]);
                j++;
            }
        }
        while(i<=m)
        {
            sorted.push_back(nums[i]);
            i++;
        }
        while(j<=r)
        {
            sorted.push_back(nums[j]);
            j++;
        }
        for(int k=l;k<=r;k++)
        {
            nums[k]=sorted[k-l];
        }
        
    }
    void mergeSort(int l, int r, vector<int>&nums)
    {
        if(l<r)
        {
            int mid = (l+r)/2;
            mergeSort(l, mid, nums);
            mergeSort(mid+1, r, nums);
            merge(l, r, nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(0, nums.size()-1, nums);
        return nums;
    }
};