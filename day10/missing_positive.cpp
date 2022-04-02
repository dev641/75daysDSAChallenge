#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
          int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1])
                swap(nums[i],nums[nums[i]-1]);
        }
        for(int i=0;i<n;i++)
            if(nums[i]!=i+1)
                return i+1;
        
        return n+1;
        // if(nums.size()==1 and nums[0]!=1)
        //     return 1;
        // else if(nums.size()==1 and nums[0]==1)
        //     return 2;
        
        // int mini=INT_MAX;
        // for(int i:nums)
        // {
        //     mini=min(i,mini);
                
        // }
        // if(mini<0){
        //     for(int i=0;i<nums.size();i++){
        //     nums[i]+=abs(mini)+1;
        // }
        // }
        // int n=nums.size();
        // int res=0;
        // for(int i=0;i<nums.size();i++){
        //     int actual = mini<0 ? abs(nums[i])-abs(mini)-1:abs(nums[i]);
        //     if(actual<=0||actual>n)
        //         continue;
        //     else 
        //     {
        //         if(nums[actual-1]<0){
        //             continue;
        //         }
        //         nums[actual-1]=-1*nums[actual-1];
        //     }
        // }
       
        // int i;
        // for(i=0;i<n;i++)
        // {
        //      if(nums[i]>=0)
        //     {
        //         res=i+1;break;
        //     }
        // }
        // if(res==0)
        //     res=i+1;
        // return res;
    }
};
int main(){
int n;
cin>>n;
vector<int>nums(n,0);
for(int i=0;i<n;i++)
 cin>>nums[i];
Solution ob;
int res=ob.firstMissingPositive(nums);
cout<<res;
return 0;
}