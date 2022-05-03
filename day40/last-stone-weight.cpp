class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        int ans=0;
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b= pq.top();
            pq.pop();
            if(a!=b)
                pq.push(a-b);
            else if(a==b)
                continue;
        }
        if(!pq.empty())
            ans=pq.top();
        else
            ans=0;
        return ans;
    }
};