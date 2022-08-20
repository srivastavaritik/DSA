class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto it:operations)
        {
            if(it=="++X"||it=="X++")x++;
            else x--;
        }
        return x;
    }
};