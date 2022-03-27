class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int n=nums.size();
        for(auto i:mp){
            if(i.second>n/2)
                ans=i.first;
        }
        return ans;
    }
};
