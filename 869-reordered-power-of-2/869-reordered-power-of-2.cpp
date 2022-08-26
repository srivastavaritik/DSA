class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string givenNumber = to_string(n);
        sort(givenNumber.begin(), givenNumber.end());
        for(int i=0;i<31;i++)
        {
            int curr = pow(2,i);
            string currPowOf2 = to_string(curr);
            sort(currPowOf2.begin(), currPowOf2.end());
            if(givenNumber == currPowOf2) return true;
        }
        return false;
    }
};