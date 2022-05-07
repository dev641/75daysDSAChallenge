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
        fun(tmp,nums,i+1,tar); 
        tmp.push_back(nums[i]);
        fun(tmp,nums,i,tar-nums[i]);
        tmp.pop_back();
    } 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(),candidates.end());

        vector<int>tmp;
        fun(tmp,candidates,0,target);
        return res;
    }
};