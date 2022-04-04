class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        vector<int>res;
        for(int i=0;i<s.length();i++){
            mp[s[i]]=i;
        }
        int maxi=0,prev=-1;
        for(int i=0;i<s.length();i++){
            maxi=max(maxi,mp[s[i]]);
            if(i==maxi){
                res.push_back(maxi-prev);
                prev=maxi;
            }
        }
        return res;
    }
};