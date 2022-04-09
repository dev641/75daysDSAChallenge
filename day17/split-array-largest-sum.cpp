class Solution {
public:
    bool isValid(vector<int>& nums, int mid,int m){
        int count=0,sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mid||count>m)
                return false;
            if(sum+nums[i]>mid){
                sum=nums[i];
                count++;
            }
            else sum+=nums[i];
        }
        return count<m;
    }
    int splitArray(vector<int>& nums, int m) {
       int maxi=INT_MIN,sum=0; 
        for(int i:nums){
            maxi=max(maxi,i);
            sum+=i;
        }
        while(maxi<sum){
            int mid=(maxi+sum)/2;
            if(isValid(nums,mid,m)){
                sum=mid;
            }
            else
                maxi=mid+1;
        }
        return maxi;
    }
};