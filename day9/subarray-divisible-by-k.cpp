#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int>mp;
        int counter=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem==0)
                counter++;
            if(rem<0)
                rem+=k;
            if(mp.find(rem)!=mp.end())
                counter+= mp[rem];
            mp[rem]++;
        }
        return counter;
    }
};
int main(){

vector<int>v={4,5,0,-2,-3,1};
Solution ob;
int res=ob.subarraysDivByK(v,5);
cout<<res;
return 0;
}