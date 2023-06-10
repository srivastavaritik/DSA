#define ll long long
class Solution {
public:
    bool isPossible(int n, int ind, int msum, int mval) {
        ll int emptyL = ind;
        ll int emptyR = n - ind - 1;
        ll int val = mval - 1, sum = 0;
        // left sum
        if(emptyL > val) {
            sum += (val * (val + 1)) >> 1;
            sum += (emptyL - val);
        }
        else {
            sum += (val * (val + 1)) >> 1;;
            ll int rem = val - emptyL;
            sum -= (rem * (rem + 1)) >> 1;
        }   

        if(emptyR > val) {
            sum += (val * (val + 1)) >> 1;
            sum += (emptyR - val);
        }
        else {
            sum += (val * (val + 1)) >> 1;;
            ll int rem = val - emptyR;
            sum -= (rem * (rem + 1)) >> 1;
        }
        return sum + mval <= msum; 

    }
    int maxValue(int n, int index, int maxSum) {
        int l = 1, h = maxSum, res = 0;
        while(l <= h) {
            int m = (l + h) >> 1;
            if(isPossible(n, index, maxSum, m)) {
                l = m + 1;
                res = m;
            }
            else {
                h = m - 1; 
            }
        }
        return res;
    }
};