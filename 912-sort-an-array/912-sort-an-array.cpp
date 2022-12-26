class Solution {
public:
    
    void merge(vector<int>&arr, int s, int e)
    {
        int i=s;
        int mid = (s+e)/2;
        int j=mid+1;
        vector<int> temp;
        while(i<=mid && j<=e)
        {
            if(arr[i]<arr[j])
            {
                temp.push_back(arr[i]);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while(j<=e)
        {
            temp.push_back(arr[j]);
            j++;
        }
        int k=0;
        for(int i=s;i<=e;i++)
        {
            arr[i]=temp[k];
            k++;
        }
        return;
    }
    
    void mergeSort(vector<int> &arr, int s, int e)
    {
        if(s>=e) return;
        int mid = (s+e)/2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);
        merge(arr, s, e);
    }
    
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};