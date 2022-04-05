#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subArraysWithAtmostK(vector<int>&nums,int k){
        int start=0,end=0;
        int count=0;
        int res=0;
        unordered_map<int,int>mp;
        for(;end<nums.size();){
            mp[nums[end]]++;
            while(mp.size()>k){
                 mp[nums[start]]--;
             if(mp[nums[start]]==0)
                 mp.erase(nums[start]);
             start++;
                  
            }
            res+=end-start+1;
            end++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subArraysWithAtmostK(nums,k)-subArraysWithAtmostK(nums,k-1);
    }
};
int main(){
int n,k;
cin>>n>>k;
vector<int>v(n,0);
for(int i=0;i<n;i++)
cin>>v[i];
Solution ob;
int res=ob.subarraysWithKDistinct(v,k);
cout<<res;
return 0;
}