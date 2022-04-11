typedef pair<int, int> pi;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int>res;
        priority_queue<pi> pq;
        for(auto i:mp){
           pq.push(make_pair(i.second,i.first));
        }
        int c=0;
        while(c<k){
            res.push_back(pq.top().second);
            pq.pop();
            c++;
        }
        return res;
    }
};