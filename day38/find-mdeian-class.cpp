class MedianFinder {
    priority_queue<int,vector<int>>pqmax;
    priority_queue<int,vector<int>,greater<int>>pqmin;
public:
    MedianFinder() { 
    }
     void balanceHeap(){
         if(pqmax.size()>pqmin.size() and pqmax.size()-pqmin.size()>1)
         {
             pqmin.push(pqmax.top());
             pqmax.pop();
         }
         else if(pqmax.size()<pqmin.size() and pqmin.size()-pqmax.size()>1)
         {
             pqmax.push(pqmin.top());
             pqmin.pop();
         }
     }
    void addNum(int num) {
        if(pqmax.empty()||pqmax.top()>=num){
            pqmax.push(num);   
        }
        else{
            pqmin.push(num);
        }
        balanceHeap();
    }
    
    double findMedian() {
      if(pqmax.size()==pqmin.size())
          return (pqmax.top()+pqmin.top())/2.0;
      else if(pqmax.size()>pqmin.size())
          return pqmax.top();
      else 
          return pqmin.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */