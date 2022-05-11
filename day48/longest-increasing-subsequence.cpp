class Solution {
public:
   int recur( vector<vector<int>>&dp,vector<int> &nums,int idx1, int idx2)
     {
    int n = nums.size(); 
    if (idx2 >=n||idx1>=n)
    { 
        return 0;
    }
    int t1 = 0;
    int t2 = 0;
    if(dp[idx1][idx2]!=-1){
    return dp[idx1][idx2];
    }
    if (nums[idx1] < nums[idx2])
    {   
        t1 = 1+recur(dp,nums,idx2, idx2 + 1);
    }
    t2 = recur(dp,nums,idx1, idx2 + 1);
    return dp[idx1][idx2] = max(t1, t2);
}

    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,0));
    //     int n=nums.size();
    //     int ans=0;
    //     for(int i=0;i<nums.size();i++){
    //          int t=recur(dp,nums,i,i+1);
    //          ans=max(ans,t+1);
    // }
    //     return ans;
//         int ans=1;
        
//         for(int i=nums.size()-1;i>=0;i--){
//         for(int j=nums.size()-1;j>=i+1;j--){
//         if(nums[i]<nums[j]){
//         dp[i][j]=max(1+dp[j][j+1],dp[i][j+1]);
//         }
//         else{
//         dp[i][j]=dp[i][j+1];
//         }
//         ans=max(ans,dp[i][j]+1);
//         }
//         }
        
        
//         return ans;
        vector<int>dp;
        dp.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>dp.back())
            {
                 dp.push_back(nums[i]);
            }
            else{
                int ind=lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
                dp[ind]=nums[i];
            }
        }
        return dp.size();

    }
};