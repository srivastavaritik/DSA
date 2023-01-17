class Solution {
public:
    int minFlipsMonoIncr(string s) {
         int flipcount = 0, onecount = 0;
        for (auto i : s)
        { 
 //keep track of all one (we will use onecount in else condition if we need)  
//if we want flip one into 0
            if (i == '1')
                onecount++;
            else{
                flipcount++;
            flipcount = min(flipcount, onecount);
            }
        }
        return flipcount;
    }
};