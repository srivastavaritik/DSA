class Solution {
public:
    int product(int n)
    {
        if(n<=1) return 1;
        int d = n%10;
        n=n/10;
        return d*product(n);
    }
    int sum(int n)
    {
        if(n<=0) return 0;
        int d = n%10;
        n=n/10;
        return d+sum(n);
    }
    int subtractProductAndSum(int n) {
     return product(n)-sum(n);   
    }
};