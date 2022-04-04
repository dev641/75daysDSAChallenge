class Solution {
public:
    void sortColors(vector<int>& nums) {
         
        // int red=0,white=0,blue=0;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==0)
        //         red++;
        //     else if(nums[i]==1)
        //         white++;
        //     else 
        //         blue++;
        // }
        // int i=0;
        //     while(red--)
        //         nums[i++]=0;
        //     while(white--)
        //         nums[i++]=1;
        //      while(blue--)
        //          nums[i++]=2;
        int i=0,start=0,end=nums.size()-1;
        while(i<=end){
            if(nums[i]==0)
                swap(nums[i++],nums[start++]);
            else if(nums[i]==2)
                swap(nums[i],nums[end--]);
            else i++;
        }
        
    }
};