class Solution {
public:
    vector<string> cellsInRange(string s) {
        char r1=s[0], c1=s[1], r2=s[3], c2=s[4];
        vector<string>ans;
        for(char i=r1; i<=r2;i++)
        {
            for(char j=c1;j<=c2;j++)
            {
                string str(1,i);
                str+=j;
                ans.push_back(str);
            }
        }
        return ans;
    }
};