class Solution {
public:
    void fun(vector<vector<int>>&res,vector<int>&v,vector<int>&nums,int i){
        if(i==nums.size()){
            res.push_back(v);
            return ;
        }
        fun(res,v,nums,i+1);
        v.push_back(nums[i]);
        fun(res,v,nums,i+1);
        v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>v;
        vector<vector<int>>res;
        fun(res,v,nums,0);
        return res;
    }
};