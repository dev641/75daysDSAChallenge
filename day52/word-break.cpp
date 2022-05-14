class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
         int n=s.length();
        vector<bool>dp(n+1,0);
        dp[n]=true;
        unordered_set<string>uset;    
        
        for(auto i:wordDict)
            uset.insert(i);
        
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(dp[j+1] && uset.find(s.substr(i,j-i+1))!=uset.end()){
                    dp[i]=true;
                    break;
            }
            }
        }
        return dp[0];
    }
};