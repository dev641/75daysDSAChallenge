class Solution {
public:
    vector<string>str={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void fun(vector<string>&res,string ques,int i,int n,string ans){
        if(i==n){
            res.push_back(ans);
            return;
        }
        for(int j=0;j<str[ques[i]-'0'].length();j++){
            // string temp=ans;
            fun(res,ques,i+1,n,ans+str[ques[i]-'0'][j]);
         
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.length()==0)
            return res;
        fun(res,digits,0,digits.length(),"");
        return res;
    }
};