class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       
        vector<vector<int>>res;
        sort(intervals.begin(),intervals.end());
        int start=intervals[0][0],end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            vector<int>temp;
            if(end>=intervals[i][0]){
              start=min(start,intervals[i][0]);
              end=max(end,intervals[i][1]);
            }
            else{
               temp.push_back(start);
                temp.push_back(end);
                res.push_back(temp);
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        res.push_back({start,end});
        return res;
    }
};