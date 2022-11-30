class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto i:arr){
           m[i]++;
        } // firstly we find the frequency in map of integer
       vector<int >temp;
        for(auto i:m){
           temp.push_back(i.second);
        }  // make a vector of all the frequencies
        unordered_map<int,int> m1;
        for(auto i:temp){
            m1[i]++;
        } // again make the map of frequency
        for(auto i:m1){
            if(i.second!=1){return false;}
        } // check these are unique or not, if not return false     otherwise true
        return true;;
    }
};