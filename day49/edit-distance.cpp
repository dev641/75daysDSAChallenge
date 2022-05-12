class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.length(),n=word2.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(int i=0;i<=m;i++)
            dp[i][0]=i;
        for(int j=0;j<=n;j++)
            dp[0][j]=j;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int ins=dp[i][j-1];
                    int del=dp[i-1][j];
                    int rep=dp[i-1][j-1];
                    dp[i][j]=1+min({ins,del,rep});
                }
            }
        }
        return dp[m][n];
//          vector<int> prev(n+1), cur(n+1);
        
//         for(int i=0;i<=m;i++){
//             for(int j=0;j<=n;j++){
//                 if(i==0) cur[j] = j;
//                 else if(j==0) cur[j] = i;
//                 else if(word1[i-1]==word2[j-1]) cur[j] = prev[j-1];
//                 else{
//                     int ins = cur[j-1];
//                     int del = prev[j];
//                     int rep = prev[j-1];
//                     cur[j] = 1 + min({ins, del, rep});
//                 }
//             }
//             prev = cur;
//         }
//         return prev[n];
        // vector<int> prev(n+1);
        // int topLeft, top, left;
        // for(int i=0;i<=m;i++){
        //     for(int j=0;j<=n;j++){
        //         if(i==0) left = j;
        //         else if(j==0) left = i;
        //         else{
        //             top = prev[j];
        //             if(word1[i-1]==word2[j-1]) left = topLeft;
        //             else left = 1 + min({topLeft, top, left});   
        //         }
        //         topLeft = prev[j];
        //         prev[j] = left;
        //     }
        // }
        // return prev[n];
    }
};
