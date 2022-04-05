class Solution {
public:
//     int fun(string s,char ch,char maxChar,int i,int k){
//         if(i==s.length())
//             return 0;
//         int count=0;
//         string str=s,res="";
//         int maxlen=0;
//         for(;i<s.length();i++){
//            if(count==k)
//                 break;
//             if(s[i]==maxChar)
//                 res+=s[i];
//             else if(count<k and s[i]==ch){
//                 s[i]=maxChar;
//                 res+=s[i];
//                 count++;
//             }
//             else {
//                 res="";
//             }
//             maxlen=max(maxlen,(int)res.length());
            
//         }
//         int otherLen=fun(str,ch,maxChar,i,k);
//         return max(maxlen,otherLen);
        
//     }
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        // for(char i:s)
        //     mp[i]++;
        // int ind=0;
        // char maxCh;
        // for(auto i:mp){
        //    if(ind<i.second){
        //        ind=i.second;
        //        maxCh=i.first;
        //    } 
        // }
        // int maxLen=0;
        // for(auto i:mp){
        //     if(i.first!=maxCh){
        //         maxLen=max(maxLen,fun(s,i.first,maxCh,0,k));
        //     }
        // }
        // return maxLen;
          int start=0;
        int maxCount=0;
        int res=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
            maxCount=max(maxCount,mp[s[i]]);
            while (i-start+1-maxCount>k)
            {   
               mp[s[start]]--;
               start++;
               
            }
            res=max(res,i-start+1);
        }
        return res;
    }
};