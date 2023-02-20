class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);

        int low=0,high=nums.size()-1;
        
        while (low <= high) {
            int mid = low + (high-low)/2;

            if (nums[mid] < target)
                low = mid+1;
            else
                high = mid-1;
        }
        return low;
    }
};