class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int> mp1;
        map<int,int> mp2;
        vector<vector<int>> ans;
        vector<int> first;
        vector<int> second;

        for(int i=0;i<matches.size();i++){
                mp1[matches[i][0]]=1;
                mp2[matches[i][1]]++;
        } 
        for(int i=0;i<matches.size();i++){
            int a=matches[i][1];
            if(mp1.find(a)!=mp1.end()){
                mp1[a]=0;
            }
        }
         for(auto value:mp1){
            if(value.second==1){
                first.push_back(value.first);
            }
        }
       
        for(auto value:mp2){
            if(value.second==1){
                second.push_back(value.first);
            }
        }
        ans.push_back(first);
        ans.push_back(second);
        return ans;
    }
};