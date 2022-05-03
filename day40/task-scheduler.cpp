class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)
            return tasks.size();
        int count=0;
        vector<int>task(26,0);
        for(int i=0;i<tasks.size();i++)
            task[tasks[i]-'A']++;
        int max_freq=0;
        for(int i=0;i<26;i++){
            if(task[i]==0)
                continue;
            if(max_freq<task[i]){
                max_freq=task[i];
                count=1;
            }
            else if(max_freq==task[i])
                count++;
        }
        int ans=(max_freq-1)*(n+1)+count;
        return ans>tasks.size()? ans:tasks.size();
        
        
    }
};