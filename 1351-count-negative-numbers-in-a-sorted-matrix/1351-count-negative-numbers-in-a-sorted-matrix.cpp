class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int c=0;
        for(auto it: grid)
        {
            for(auto i:it)
            {
                if(i<0)c++;
            }
        }
        return c;
    }
};