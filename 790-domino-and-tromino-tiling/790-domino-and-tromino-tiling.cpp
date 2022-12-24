class Solution {
public:
    int numTilings(int n) {
        int p1=1, p2=2, p3=5, M=1e9+7;
        if(n==1){return 1;}
        if(n==2){return 2;}
        if(n==3){return 5;}
        for(int i=4; i<=n; i++){
            int curr=((2*(p3%M))%M+p1%M)%M;
            p1=p2%M;
            p2=p3%M;
            p3=curr%M;
        }
        return p3%M;
    }
};