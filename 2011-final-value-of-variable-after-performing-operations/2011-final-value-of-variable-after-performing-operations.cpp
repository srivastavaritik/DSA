class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0, plus=0,minus=0;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="++X" || operations[i]=="X++") plus++;
            else minus++;
        }
        x=plus-minus;
        return x;
    }
};