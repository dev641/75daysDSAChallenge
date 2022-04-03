class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int mx=INT_MIN;
        deque<int>dq;
        dq.push_back(0);
        int i=1,n=points.size();
        while(i<n){
          while(!dq.empty() and points[i][0]-points[dq.front()][0]>k)
              dq.pop_front();
     if(!dq.empty()){
        mx=max(mx,points[dq.front()][1]+points[i][1]-points[dq.front()][0]+points[i][0]);
            }
        
        while(!dq.empty() and points[dq.back()][1]-points[dq.back()][0]<points[i][1]-points[i][0]) dq.pop_back();
     dq.push_back(i);
        i++;
        }
        return mx;
    }
        
};