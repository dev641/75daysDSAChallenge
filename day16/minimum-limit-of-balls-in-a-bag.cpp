class Solution {
public:
    bool isValid(vector<int>&nums,int mid,int k){
        int total=0;
        for(auto i:nums){
            total+=i/mid-(i%mid==0);
        }
        return total<=k;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
       int h=INT_MIN,l=1,res=1;
        for(int i=0;i<nums.size();i++)
            h=max(h,nums[i]);
        while(l<=h){
            int mid=(l+h)/2;
            if(isValid(nums,mid,maxOperations)){
                res=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return res;
    }
};