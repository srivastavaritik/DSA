class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=1;
        while(n!=1)
        {
            int temp=a;
            a+=b;
            b=temp;
            n--;
        }
        return a;
    }
};