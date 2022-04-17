class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('||s[i]=='{'|| s[i]=='['){
                st.push(s[i]);
            }
            else if(!st.empty() and st.top()=='(' and s[i]==')')
                st.pop();
            else if(!st.empty() and st.top()=='{' and s[i]=='}')
                st.pop();
            else if(!st.empty() and st.top()=='[' and s[i]==']')
                st.pop();
            else{
                st.push(s[i]);
            }
        }
        return st.empty();
    }
};