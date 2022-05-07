class Solution {
public:
    vector<vector<int>>res;
    void fun(vector<int>&tmp,vector<int>&nums,int i,int tar){
        if(tar<0)
            return ;
        if(tar==0){
            res.push_back(tmp);
            return ;      
        }
        if(i==nums.size())
           return;
        tmp.push_back(nums[i]);
        fun(tmp,nums,i+1,tar-nums[i]);
        tmp.pop_back();
        while(i+1<nums.size() and nums[i]==nums[i+1])
            i++;
        fun(tmp,nums,i+1,tar); 
    } 
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
           vector<int>tmp;
           sort(candidates.begin(),candidates.end());
           fun(tmp,candidates,0,target);
        return res;
    }
};