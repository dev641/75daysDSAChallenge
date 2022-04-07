#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1,n=nums.size();
     
        vector<int>res;
        if(n==1 and nums[0]==target)
            return {0,0};
        if(n==2 ){
            if(nums[0]==nums[1]==target)
                return {0,1};
            else if(nums[0]==target)
                return {0,0};
            else if(nums[1]==target)
                return {1,1};
            else return {-1,-1};
        }
            
        while(l<=h){
            int mid=l+(h-l)/2;
            if(target==nums[mid]){
                if(target>nums[mid-1] and target<nums[mid+1])
                    return {mid,mid};
                    if(mid-1>=0 and target>nums[mid-1])
                    {
                        res.push_back(mid);
                        l=mid+1;
                    }
                    else if (mid+1<n and target<nums[mid+1])
                    {
                         res.push_back(mid);
                         h=mid-1;
                    }
            }
            else if(nums[mid]<target)
                l=mid+1;
            else h=mid-1;
                
        }
       
        if(res.size()==0)
            return {-1,-1};
        
         if(res[0]>res[1])
            swap(res[0],res[1]);
            
        
        return res;
    }
};
int main(){
int n,tar;
cin>>n>>tar;
vector<int>v(n,0);
for(int i=0;i<n;i++){
    cin>>v[i];
}
Solution ob;
vector<int>res=ob.searchRange(v,tar);
cout<<res[0]<<" "<<res[1];
return 0;
}