class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        string t1=text1,t2=text2;
        vector<vector<int>>dp(t1.size()+2,vector<int>(t2.size()+2,-1));
        // tabulation
        for(int i=0;i<=t2.size();i++)
            dp[0][i]=0;
         for(int i=0;i<=t1.size();i++)
            dp[i][0]=0;
        for(int i=1;i<=t1.size();i++)
            for(int j=1;j<=t2.size();j++)
            {
                
                 if(t1[i-1]==t2[j-1])
                      dp[i][j]=1+dp[i-1][j-1];
                 else
                      dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        // return statement for tabulation
        return dp[t1.size()][t2.size()];
    }
};