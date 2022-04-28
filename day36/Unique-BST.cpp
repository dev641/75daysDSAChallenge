class Solution {
    
public:
    Solution(){
        set();
    }
    int dp[20]={0};
    void set(){
      for(int i=0;i<20;i++){
          if(i==0)
              dp[i]=1;
          else if(i==1|| i==2)
              dp[i]=i;
          else 
              dp[i]=-1;
      }
    }
     int fun(int n){
        if(dp[n]!=-1)
            return dp[n];
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=numTrees(i)*numTrees(n-i-1);
        dp[n]=sum;
        return sum;     
   }
    int numTrees(int n) {    
        int ans=fun(n);
        return ans;
    }
};