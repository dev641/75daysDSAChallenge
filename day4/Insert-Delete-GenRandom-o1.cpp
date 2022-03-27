class setObj{
    public:
     unordered_map<int,int>mp;
};
class RandomizedSet {
   setObj s;
public:
    RandomizedSet() {
      // s = new setObj();
    }
    
    bool insert(int val) {
        if(s.mp.find(val)==s.mp.end())
        {
             s.mp[val]=1;
            return true;
        }
             return false;
       
    }
    
    bool remove(int val) {
        if(s.mp.find(val)!=s.mp.end()){
            s.mp.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int n= rand()%s.mp.size();
        auto it=next(s.mp.begin(),n);
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */