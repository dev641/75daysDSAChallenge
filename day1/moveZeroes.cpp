class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // int i,j;
        // // i=0,j=nums.size()-1;
        // //
        // i=0,j=1;
        //  while(i<nums.size() and j<nums.size()){
        //        while(nums[i]!=0) i++;
        //        while(nums[j]==0) j++;
        //        if(i<nums.size() and j<nums.size())
        //            swap(nums[i],nums[j]);
        //  };
        int zero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
                nums[zero++]=nums[i];
        }
        for(;zero<nums.size();zero++)
            nums[zero]=0;
    }
};
