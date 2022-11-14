class Solution {
public:
    int smallestEvenMultiple(int n) {
        int i=n;
        while(true)
        {
            if(i%n==0 and i%2==0) 
            {
                return i;
                break;
            }
            else i++;
        }
        return -1;
    }
};