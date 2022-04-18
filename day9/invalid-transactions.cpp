
class Solution {
public:
    vector<string>spl(string s,string del=" "){
      int st=0;
        int e=s.find(del);
        vector<string>v;
        while(e!=-1)
        {
            v.push_back(s.substr(st,e-st));
            st=e+del.size();
            e=s.find(del,st);
        }
         v.push_back(s.substr(st,e-st));
        return v;
    }
    bool fun(vector<string>s,vector<vector<string>>list){
     if(stoi(s[2])>1000)
         return false;
     for(auto i:list){
         if(abs(stoi(s[1])-stoi(i[1]))<=60 and s[3]!=i[3])
             return false;
     }
     return true;
          
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string>res;
        unordered_map<string,vector<vector<string>>>mp;
        for(int i=0;i<transactions.size();i++){
            string t1=transactions[i];
            vector<string>trx=spl(t1,",");
            mp[trx[0]].push_back(trx);
        }
        
        for(string i:transactions){
            vector<string>trx=spl(i,",");
            if(fun(trx,mp[trx[0]]))
                res.push_back(i);
        }
        return res;
    }
};
