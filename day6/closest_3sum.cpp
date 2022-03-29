#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
     int closestsum=INT_MAX;
     int sum=INT_MIN;
    void twosum(vector<int>nums,int i,int target){
        int l=i+1,r=nums.size()-1;
       
        while(l<r){
            int tsum=nums[i]+nums[l]+nums[r];
            if(tsum>=target and tsum<closestsum){
                closestsum=min(tsum,closestsum);
                
            }
           if(tsum<target)
           {
               sum=max(tsum,sum);
               l++;
           }
            else r--;
        }
       
        // return closestsum;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size()<=3){
            int sum=0;
            for(auto i:nums)
                sum+=i;
            return sum;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            // if(i==0 || (i>0 and nums[i]!=nums[i-1]))
                twosum(nums,i,target);
        }
         if(closestsum==INT_MAX)
            closestsum=sum;
         else if(sum!=INT_MIN)
         {
             if(abs(closestsum-target)>abs(sum-target))
                 closestsum=sum;
         }
             
        return closestsum;
        //  int i,j,k;
        // int ans=0,n=nums.size();
        // int diff=INT_MAX,min_d=INT_MAX;
        //  sort(nums.begin(),nums.end());
        // for( i=0;i<n;i++)
        // {
        //     int x=nums[i];
        //     int p=i+1,q=n-1;
        //     while(p<q){
        //         int y=nums[p],z=nums[q];
        //         int sum=x+y+z;
        //         diff=abs(target-sum);
        //         if(diff<min_d){
        //             ans=sum;
        //             min_d=diff;
        //         }
        //         if(sum==target) break;
        //         else if(sum>target) q--;
        //         else p++;
        //     }
        // }
        // return ans;
    }
};
int main(){
int n,target;
cin>>n>>target;
vector<int>nums(n,0);
for(int i=0;i<n;i++)
 cin>>nums[i];
 Solution ob;
 int res=ob.threeSumClosest(nums,target);
 cout<<res;
return 0;
}