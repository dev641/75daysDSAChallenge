class Solution {
public:
    // int store(vector<int>&nums,int curr){
    //     if(curr==nums[curr])
    //         return curr;
    //     int nxt=nums[curr];
    //     nums[curr]=curr;
    //     return store(nums,nxt);
    // }
//     int lessThanEqualTo(vector<int>&nums,int val){
//         int count=0;
//         for(auto i:nums)
//             if(i<=val)
//                 count++;
//         return count;
//     }
//     int BinSearch(vector<int>&nums){
//         int mid=0;
//         int low=1,high=nums.size();
//         int ans=-1;
//         while(low<=high){
//             mid=(low+high)/2;
//             if(lessThanEqualTo(nums,mid)>mid){
//                 ans=mid;
//                 high=mid-1;
                
//             }
//             else low=mid+1;
//         }
//         return ans;
//     }
    int findDuplicate(vector<int>& nums) {
//         Method 1
        // sort(nums.begin(),nums.end());
        // int j=0;
        // for(int i=1;i<nums.size();i++){
        //     if(nums[i]==nums[j])
        //         break;
        //     else j++;
        // }
        // return nums[j];
//         Method 2
        // unordered_map<int,int>mp;
        // int res=-1;
        // for(auto i:nums)
        // {
        //     if(mp.find(i)!=mp.end()){
        //         res=i;
        //         break;
        //     }
        //     mp[i]++;
        // }
        // return res;
//         Method 3
        // int curr=0;
        // int dup=-1;
        // for(int i=0;i<nums.size();i++){
        //    int curr=abs(nums[i]);
        //     if(nums[curr]<0)
        //     {
        //         dup=curr;
        //         break;
        //     }
        //     nums[curr]*=-1;
        // }
        // for(auto i:nums){
        //         i=abs(i);
        // }
        // return dup;
//         Method 4
         // return store(nums,0);
//         Method 5
        // while(nums[0]!=nums[nums[0]])
        //     swap(nums[0],nums[nums[0]]);
        // return nums[0];
//         Method 6 binary Search
         // return BinSearch(nums);
//         Method 7
        int tortoise=nums[0];
        int hare=nums[0];
        do{
            tortoise=nums[tortoise];
            hare=nums[nums[hare]];
        }while(tortoise!=hare);
        
        tortoise=nums[0];
        while(tortoise!=hare)
        {
            tortoise=nums[tortoise];
            hare=nums[hare];
        }
        return hare;
    }
};