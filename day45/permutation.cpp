class Solution {
public:
    void fun(vector<vector<int>>&res,vector<int>&v,vector<int>nums,int i){
        if(i==nums.size()){
            // if(v.size()==nums.size())
                res.push_back(v);
            return ;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[j],nums[i]);
            v.push_back(nums[i]);
            fun(res,v,nums,i+1);
            v.pop_back();
            swap(nums[j],nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>v;
        fun(res,v,nums,0);
        return res;
    }
};