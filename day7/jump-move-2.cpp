class Solution {
public:   
    int jump(vector<int>& nums) {
       int jump=0,curr=0,maxjump=0;
        for(int i=0;i<nums.size()-1;i++){
            maxjump=max(maxjump,nums[i]+i);
            if(i==curr){
                curr=maxjump;
                jump++;
            }
        }
        return jump;
    }
};