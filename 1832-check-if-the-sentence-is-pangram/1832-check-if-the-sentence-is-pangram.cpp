class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int>mpp;
        for(int i=0;i<sentence.size();i++)
        {
            mpp[sentence[i]]++;
        }
        if(mpp.size()>=26) return true;
        return false;
    }
};