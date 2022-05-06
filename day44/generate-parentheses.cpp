class Solution {
public:
    void solve(int open,int close,string s,vector<string>&res,int n){
        if(s.length()==2*n){
            res.push_back(s);
            return ;
        }
        if(open<n)
            solve(open+1,close,s+"(",res,n);
        if(open>close)
            solve(open,close+1,s+")",res,n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        // if(n==0)
        //      res.push_back("");
        // else{
        //     for(int i=0;i<n;++i){
        //         for(string left : generateParenthesis(i)){
        //             for(string right : generateParenthesis(n-1-i)){
        //                 res.push_back("("+left+")"+right);
        //             }
        //         }
        //     }
        // }
        // return res;
        solve(0,0,"",res,n);
        return res;
    }
};