class Solution {
public:
    int minFlips(int a, int b, int c){
        int ans=0;
        for(int i=31;i>=0;i--){
            int p,q,r;
            p=a&(1<<i);
            q=b&(1<<i);
            r=c&(1<<i);
            if(r!=0){
                if(p==0 and q==0)   ans++;
            }
            else{
                if(p!=0)    ans++;
                if(q!=0)    ans++;
            }
        }
        return ans;
    }
};