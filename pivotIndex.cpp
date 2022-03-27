class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       //  int i=0,j=nums.size();
       //  int leftsum=0;
       //  for(int i=1;i<nums.size()-1;i++)
       //      leftsum+=nums[i];
       //  if(leftsum+nums[nums.size()-1]==0)
       //      return 0;
       //  if(nums[0]+leftsum==0)
       //      return nums.size()-1;
       //  int l=0,h=nums.size()-1;
       //  int tsum=leftsum+nums[l]+nums[h];
       //  if(tsum<0){
       //  int lsum=0,rsum=0;
       //  while(l<h){
       //    if(lsum>rsum)
       //     lsum+=nums[l++];
       //     else if(rsum>lsum)
       //     rsum+=nums[h--]; 
       //      else{
       //           if(l==h-1 and ((lsum+nums[l]==rsum+nums[h]))) return l;
       //          if(nums[l]==0)
       //              l++;
       //          if(nums[h]==0)
       //              h--;
       //          else if(l==h)
       //              break;
       //          else
       //          rsum+=nums[h--];
       //      }
       // }
       //      if(lsum==rsum)
       //  return l;
       //  return -1;
       //  }
       //  int lsum=0,rsum=0;
       //  while(l<h){
       //    if(lsum<rsum)
       //     lsum+=nums[l++];
       //     else if(rsum<=lsum)
       //     rsum+=nums[h--]; 
       // }
       //  if(lsum==rsum)
       //  return l;
       //  return -1;
        int sum=0,l=0,r;
        for(auto i:nums)
             sum+=i;
        r=sum;
        for(int i=0;i<nums.size();i++){
            r-=nums[i];
            if(l==r)
                return i;
            l+=nums[i];
        }
        return -1;
    }
};
