class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;   
        deque<int>dq;
        int l=0;
        if(k==1)
            return nums;
        int j=0;
       for(int i=0;i<nums.size();i++){
           
           while(!dq.empty() and dq.back()<nums[i])
               dq.pop_back();
           dq.push_back(nums[i]);
           
           if(i-j+1>=k){
               res.push_back(dq.front());
               if(nums[j]==dq.front()){
                   dq.pop_front();
               }
               j++;
           }
       }
        return res;
    }
};