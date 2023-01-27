class Solution {
public:
    // vector<int> dp;
    bool helper(string s ,unordered_set<string> &st, int start , vector<string> &t,vector<int>&dp){
        if(start >= s.length()){
            return true;
        }

        if(dp[start]  != -1)
            return dp[start];

        string temp ;
        for(int j=start;j<s.length();j++){
            temp += s[j];

            if(st.find(temp) != st.end()){
                // cout << temp << " " ;
                t.push_back(temp);
                if(helper(s,st,j+1,t,dp)){
                    return dp[j] = 1;
                }
                t.pop_back();
            }
        }
        return dp[start] = 0;     
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st;
        for(auto s:words){
            st.insert(s);
        }

        vector<string> ans ;
        
        for(auto s:words){
            // cout << s << endl;
            vector<string> t;
            vector<int> dp(s.length(),-1);
            if(helper(s,st,0,t,dp)){
                if(t.size() >= 2)
                    ans.push_back(s);
            }
            // cout << endl;
        }
        return ans;
    }
};