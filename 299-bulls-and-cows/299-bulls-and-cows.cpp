class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>m;
        int n=secret.length();
        int bulls=n;
        for(int i=0;i<n;i++)
        {
            if(secret[i]!=guess[i])
            {
                m[secret[i]]++;
                bulls--;
            }
                
        }
        int cows=0;
        for(int i=0;i<n;i++)
        {
            if(secret[i]!=guess[i] and m[guess[i]]>0)
            {
                m[guess[i]]--;
                cows++;
            }
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};