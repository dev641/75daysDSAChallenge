class MyHashMap {
    vector<vector<pair<int,int>>>mp;
    int sz;
public:
    MyHashMap() {
        sz=11;
        mp.resize(sz);
    }
    vector<pair<int,int>>::iterator search(int key){
        int ind=key%sz;
        auto i=mp[ind].begin();
        while(i!=mp[ind].end()){
            if(i->first==key)
                return i;
            i++;
        }
        return i;
    }
    void put(int key, int value) {
        int ind=key%sz;
        auto i=search(key);
        if(i==mp[ind].end())
            mp[ind].push_back({key,value});
          else  i->second=value;
    }
    
    int get(int key) {
       int ind=key%sz;
        auto i=search(key);
        if(i==mp[ind].end())
            return -1;
        else return i->second;
    }
    
    void remove(int key) {
        int ind=key%sz;
        auto i=search(key);
        if(i==mp[ind].end())
            return;
        else mp[ind].erase(i);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */