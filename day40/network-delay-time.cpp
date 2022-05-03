class Solution {
using ip = pair<int,int>;
    int maxtime = 0;
    void BFS(int x,vector<vector<pair<int, int>>> &graph,vector<int> &visited )  {
       priority_queue<ip, vector<ip>, greater<ip>> pq;
       pq.push({0,x});
        
        while(!pq.empty())  {
            int top = pq.top().second;
            int tsf = pq.top().first;
            pq.pop();
            
            if(visited[top])
                continue;
            visited[top] =1;
            maxtime = tsf;
            
            for(auto &i: graph[top])  {
                if(visited[i.first]==0)
                    pq.push({tsf + i.second, i.first});
            }
        }
        return;
    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n+1);
        vector<int> visited(n+1,0);
        
        for(auto &i: times)  {
            graph[i[0]].push_back({i[1], i[2]});
        }
        
        BFS(k, graph, visited);
        
        for(int i=1; i<visited.size(); ++i)  {
            if(visited[i]==0)
                return -1;
        }
        
        return maxtime;
        
    }
};