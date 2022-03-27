#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void Reverse(vector<int>&nums,int i){
        int j=nums.size()-1;
        for(;i<j;i++,j--){
            swap(nums[i],nums[j]);
        }
        
    }
    void nextPermutation(vector<int>& nums) {
        int i,j;
        for(i=nums.size()-2;i>=0;i--){
            if(nums[i+1]>nums[i]){
                break;
            }
        }
        if(i<0)
        {
           Reverse(nums,0); 
        }
        else{
            for(j=nums.size()-1;j>i;j--){
                if(nums[j]>nums[i])
                   // j=j-1;
                    break;
            }
            swap(nums[i],nums[j]);
            Reverse(nums,i+1);
        }
    }
};

int main(){
    int n;
    cin>>n;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++)
     cin>>nums[i];
    Solution ob;
    ob.nextPermutation(nums);
    for(auto i:nums)
     cout<<i<<" ";
     return 0;
}