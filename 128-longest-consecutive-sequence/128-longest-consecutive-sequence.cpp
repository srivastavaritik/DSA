class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int maxc=0;
        for(int i=0;i<nums.size();i++)
        {
            st.insert(nums[i]);
        }
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i]-1)==st.end())
            {
                int k=1,c=1;
                while(st.find(nums[i]+k)!=st.end())
                {
                    c++;
                    k++;
                }
                maxc = max(maxc, c);
            }
        }
        return maxc;
    }
};