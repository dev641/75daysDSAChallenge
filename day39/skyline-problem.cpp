class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        priority_queue<pair<int, int>> pq;
        int i = buildings[0][0];
        int idx = 1;
        bool condition = true;
        pq.push(make_pair(buildings[0][2], buildings[0][1]));
        while(!pq.empty() || idx < buildings.size()){
            while(idx < buildings.size() && i == buildings[idx][0]){
                if(pq.empty() || buildings[idx][2] > pq.top().first)
                    condition = true;
                pq.push(make_pair(buildings[idx][2], buildings[idx][1]));
                idx++;
            }
            while(!pq.empty() && pq.top().second <= i){
                pq.pop();
                condition = true;
            }
            
            if(condition == true){
                vector<int> ansI;
                ansI.push_back(i);
                if(!pq.empty())
                    ansI.push_back(pq.top().first);
                else
                    ansI.push_back(0);
                ans.push_back(ansI);
            }
            condition = false;
            if(idx < buildings.size() && !pq.empty())
                i = min(pq.top().second, buildings[idx][0]);
            else if(idx < buildings.size())
                i = buildings[idx][0];
            else
                i = pq.top().second;
        }
        return ans;
    }
};