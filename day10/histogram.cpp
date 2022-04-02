class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>>st;
        int n=heights.size();
        int maxArea=0;
        for(int i=0;i<n;i++){
            int start=i;
            while(!st.empty() and st.top().second>heights[i]){
                int ind=st.top().first;
                int height=st.top().second;
                maxArea=max(maxArea,(i-ind)*height);
                start=ind;
                st.pop();
            }
            st.push({start,heights[i]});
        }
        
        while(!st.empty()){
             int ind=st.top().first;
                int height=st.top().second;
                maxArea=max(maxArea,(n-ind)*height);
                st.pop();
        }
        return maxArea;
    }
};