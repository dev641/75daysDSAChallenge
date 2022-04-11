class Solution {
public:
    unordered_map<char,int> mp;
    bool isSorted(string s1,string s2){
    bool ans=true;
        int count=0;
     int mini=min(s1.length(),s2.length());
      for(int i=0;i<mini;i++){
          if(mp[s1[i]]<mp[s2[i]])
              break;
          else if(mp[s1[i]]>mp[s2[i]])
          {
              ans=false;break;
          }
          else count++;
      }
        
        return ans&&!(count==mini &&s1.length()>s2.length());
    }
    bool isAlienSorted(vector<string>& words, string order) { 
        for(int i=0;i<order.size();i++){
            mp[order[i]]=i;
        }
        int res=true;
        for(int i=1;i<words.size();i++){
            if(!isSorted(words[i-1],words[i]))
            {
                res=false;break;
            }
        }
        return res;
    }
};