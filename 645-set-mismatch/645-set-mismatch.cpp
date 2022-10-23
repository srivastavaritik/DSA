class Solution {
public:
vector<int> findErrorNums(vector<int>& nums) {
   int n=nums.size();
    vector<int>v;
    unordered_map<int,int>m;
    for(int i=1;i<=n;i++)
        m[i]=0;
    for(auto x:nums)
        m[x]++;
    for(auto y:m)
    {
        if(y.second==2){
            v.push_back(y.first);
            break;
        }
    }
     for(auto y:m)
    {
        if(y.second==0){
            v.push_back(y.first);
            break;
        }
    }
    return v;
    
}
};