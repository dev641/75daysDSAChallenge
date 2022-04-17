class Solution {
public:
    int search(vector<int>& nums, int target) {
        int ans=-1,n=nums.size();
        int l=0,h=n-1;
        while(l<=h){
            int mid=(l+h)/2;
            if(nums[mid]==target)
            {
                ans=mid;break;
            }
            else if(nums[l]<=nums[mid])
            {
                if(target<nums[l] || target>nums[mid]){
                    l=mid+1;
                }
                else h=mid-1;
            }
            else {
                if(target>nums[h]||target<nums[mid])
                    h=mid-1;
                else l=mid+1;
            }
        }
        return ans;
    }
};