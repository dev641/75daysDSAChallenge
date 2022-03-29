class Solution {
public:
 
    int numPairsDivisibleBy60(vector<int>& time) {
     unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<time.size();i++){
            int t=time[i]%60;
            if(t==0)
                ans+=mp[0];
            else
                ans+=mp[60-t];
            mp[t]++;
        }
        return ans;
    }
};