class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            int temp = target-nums[i];
            if(st.find(temp)==st.end()) st.insert(nums[i]);
            else 
            {
                auto it = find(nums.begin(), nums.end(), temp);
                int index = it-nums.begin();
                return {i, index};
            }
        }
        return {};
    }
};