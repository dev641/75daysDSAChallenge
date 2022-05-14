class Solution {
public:
    int minCut(string a) {
         int n = a.size(),low,high;
        vector<int> dp(n+1,INT_MAX);  // One extra length for starting position
        dp[0] = -1;
        
        for(int i=0;i<n;i++)
        {
            
            // For odd lenght palindrome
            low = i;
            high = i;
            
            while(low>=0&&high<n&&a[low]==a[high])
            {
                dp[high+1] = min(dp[low]+1,dp[high+1]); 
                low--;
                high++;
            }
            
            
            // For even length palindrome
            low = i-1;
            high = i;
            while(low>=0&&high<n&&a[low]==a[high])
            {
                dp[high+1] = min(dp[low]+1,dp[high+1]);
                low--;
                high++;
            }
            
        }
        
        return dp[n];        
        
       
    }
};