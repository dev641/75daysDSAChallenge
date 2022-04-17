class LRUCache {
public:
    unordered_map<int,list<pair<int,int>>::iterator>Cachemp;
    list<pair<int,int>>lrulist;
    int size;
    LRUCache(int capacity) {
        size=capacity;
    }
    // void moveFront(int key){
    //    int val=Cachemp[key]->second;
    //    lrulist.erase(Cachemp[key]);
    //    lrulist.push_front(make_pair(key,val));
    //     Cachemp[key]=lrulist.begin();
    // }
    
    int get(int key) {
        if(!Cachemp.count(key))
            return -1;
        lrulist.splice(lrulist.begin(),lrulist,Cachemp[key]);
        // moveFront(key);
        return Cachemp[key]->second;
    }
    
    void put(int key, int value) {
      if(Cachemp.find(key)!=Cachemp.end()){
          lrulist.splice(lrulist.begin(),lrulist,Cachemp[key]);
          // moveFront(key);
          lrulist.begin()->second=value;
          return;
      }
        if(lrulist.size()==size){
            Cachemp.erase(lrulist.back().first);
            lrulist.pop_back();
        }
        lrulist.push_front(make_pair(key,value));
        Cachemp[key]=lrulist.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */