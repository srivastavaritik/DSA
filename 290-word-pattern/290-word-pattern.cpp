class Solution {
public:
     bool wordPattern(string pattern, string s) {
        stringstream str(s);
        string word;
        string strr="";
        string strrr="";
        unordered_map<string,char> mp;
        unordered_map<char,char> mp1;
        char ch='a',chh='a';
        for(auto &x:pattern){
            if(mp1.find(x)!=mp1.end()){
                strrr+=mp1[x];
            }
            else{
                mp1[x]=chh;
                strrr+=mp1[x];
                chh++;
            }
        }
        while(str>>word){
            if(mp.find(word)!=mp.end()){
                strr+=mp[word];
            }
            else{
                mp[word]=ch;
                strr+=mp[word];
                ch++;
            }
        }
        cout<<strr<<endl;
        if(strr==strrr){
            return true;
        }
        return false;
    }
};