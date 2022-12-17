class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        // cout<<stoi("-11")<<" ";
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" ||tokens[i]=="*" ||tokens[i]=="-" ||tokens[i]=="/"){
                 long long int a=st.top();
                st.pop();
                long long int b=st.top();
                st.pop();
                if(tokens[i]=="+")
                st.push(a+b);
                if(tokens[i]=="*")
                {long long int x=a*b;
                st.push(x);
                }
                if(tokens[i]=="-")
                st.push(b-a);
                if(tokens[i]=="/")
                st.push(b/a);
                // cout<<st.top()<<" ";
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};