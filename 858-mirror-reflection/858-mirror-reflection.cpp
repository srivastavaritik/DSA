class Solution {
public:
    int mirrorReflection(int p, int q) {
        int hcf=gcd(p,q);
        int m=q/hcf; 
        int n=p/hcf; 
        if(m%2==0 && n%2==1) return 0;
        if(m%2==1 && n%2==1) return 1;
        if(m%2==1 && n%2==0) return 2;
        return -1;
    }
};