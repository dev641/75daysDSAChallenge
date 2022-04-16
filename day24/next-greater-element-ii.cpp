class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>st;
        vector<int>v(nums.size(),0);
       for(int i = nums.size() - 1;i >= 0;i--){
           while(!st.empty() and st.top()<=nums[i])
           {
               st.pop();
           }
           v[i]=st.empty()?-1:st.top();
           st.push(nums[i]);
               
       }
           for(int i = nums.size() - 1;i >= 0;i--){
           while(!st.empty() and st.top()<=nums[i])
           {
               st.pop();
           }
           v[i]=st.empty()?-1:st.top();
           st.push(nums[i]);
           

       }
        
        return v;
    }
};
