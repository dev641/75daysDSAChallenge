class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump=0,curReach=0,maxReach=0;
        for(int i=0;i<nums.size();i++){
            maxReach=max(maxReach,nums[i]+i);
            if(i==curReach){
                jump++;
                curReach=maxReach;
            }
            
        }
        if(curReach<nums.size()-1)
            return false;
        return true;
    }
};