class Solution {
public:
    bool isNumber(string s) {
        s.erase(0,s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ")+1);

        int firstE = (s.find_first_of("e")!=-1) ?s.find_first_of("e"):s.find_first_of("E");

        if(firstE == -1) return isvalid(s);
        else return isvalid(s.substr(0,firstE)) && isInteger(s.substr(firstE+1));


    }

    bool isvalid(string s){
        if(!s.empty() && (s[0]=='+' || s[0]=='-')) s.erase(s.begin());

        int no_dot=0;

        for(int i =0;i<s.size();i++){
            if(s[i]=='.')no_dot++;
            else if(!isdigit(s[i]))return false;
        }

        return no_dot<=1 && s.size()>no_dot;
    }


    bool isInteger(string s){
        if(!s.empty() && (s[0]=='+' || s[0]=='-')) s.erase(s.begin());

        for(int i = 0;i<s.size();i++){
            if(!isdigit(s[i]))return false;
        }

        return s.size();
    }
};