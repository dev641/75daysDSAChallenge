class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>>res;
        sort(nums.begin(),nums.end());
        int j,k;
        for(int i=0;i<nums.size();i++){
            int fir=nums[i];
             j=i+1,k=nums.size()-1;
            while(j<k){
                if(nums[j]+nums[k]>(0-nums[i]))
                    j--;
                else if(nums[j]+nums[k]<(0-nums[i]))
                    k++;
                else
                 res.insert({nums[i],nums[j],nums[k]});
               j++,k--;
            }
        }
        return vector(res.begin(),res.end());
    }
};

// method2
class Solution {
public:
    void twosum(vector<vector<int>>&res,int i,vector<int>&nums){
        int l=i+1;
        int r=nums.size()-1;
        while(l<r){
            int tsum=nums[i]+nums[l]+nums[r];
            if(tsum==0){
                res.push_back({nums[i],nums[l],nums[r]});
                  l++,r--;
                while(l<r and nums[l]==nums[l-1])
                    l++;
                // while(l<r and nums[r]==nums[r-1])
                //     r--;
              
            }
            else if(tsum<0)
                l++;
            else r--;
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        // set<vector<int>>res;
        // sort(nums.begin(),nums.end());
        // int j,k;
        // for(int i=0;i<nums.size();i++){
        //     int fir=nums[i];
        //      j=i+1,k=nums.size()-1;
        //     while(j<k){
        //         if(nums[j]+nums[k]>(0-nums[i]))
        //             j--;
        //         else if(nums[j]+nums[k]<(0-nums[i]))
        //             k++;
        //         else
        //          res.insert({nums[i],nums[j],nums[k]});
        //        j++,k--;
        //     }
        // }
        // return vector(res.begin(),res.end());
       vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i==0||(i>0 and nums[i]!=nums[i-1])){
                twosum(res,i,nums);
            }
        }
        return res;
    }
};