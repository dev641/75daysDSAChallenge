class RandomizedCollection {
    vector<int>v;
    unordered_map<int,set<int>>mp;
    int size;
public:
    RandomizedCollection() {
        v.resize(100005,-1);
        size=0;
    }
    
    bool insert(int val) {
        bool flag=true; 
         if(mp.count(val))
         {
           flag=false;   
         }
        mp[val].insert(size);
        v[size]=val;
            size++;
        return flag;
    }
    
    bool remove(int val) {
        if(mp.count(val)==0)
        return false;
        auto it=mp[val].end();
        --it;
        int x=*it;
        mp[val].erase(it);
        if(mp[val].size()==0)
            mp.erase(val);
        if(size==1||x==size-1){
            size--;
            v[x]=-1;
            return true;
        }
        v[x]=v[size-1];
        it=mp[v[size-1]].end();
        --it;
        mp[v[size-1]].erase(it);
        mp[v[size-1]].insert(x);
        v[size-1]=-1;
        size--;
        return true;
    }
    
    int getRandom() {
        int n=size;
        int random=rand()%n;
        return v[random];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */