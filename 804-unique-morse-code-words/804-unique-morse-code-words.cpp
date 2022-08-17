class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string> st;
    for(auto word : words)
    {
        string s;
        for(char c:word)
        {
            s+=morse[c-'a'];
        }
        st.insert(s);
    }
        return st.size();
    
    }
};