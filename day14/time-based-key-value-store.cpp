class TimeMap {
    unordered_map<string,vector<pair<string,int>>>mp;
public:
    TimeMap() {
        
    }
  
    void set(string key, string value, int timestamp) {
       mp[key].push_back({value,timestamp});
    }
    
    string get(string key, int timestamp) {
       string ans="";
        int low = 0, end = mp[key].size();
        while(low < end)
        {
            int mid = low + (end-low)/2;
            if(mp[key][mid].second > timestamp){
                end = mid;
            }
            else{
                ans = mp[key][mid].first;
                low = mid + 1;
            }
        }
        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
