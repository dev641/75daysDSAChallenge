class Solution {
public:
    
    vector<int> sortedSquares(vector<int>& nums) {
        // int l=0,h=nums.size()-1;
        // vector<int> res;
        // while(l<=h){
        //     if(abs(nums[l])>abs(nums[h])){
        //        res.push_back(pow(nums[l++],2)); 
        //     }
        //     else{
        //         res.push_back(pow(nums[h--],2));
        //     }
        // }
        // reverse(res.begin(),res.end());
        // return res;
        vector<int> res;
        for(auto i:nums){
            res.push_back(i*i);
        }
        sort(res.begin(),res.end());
        return res;
    }
};
