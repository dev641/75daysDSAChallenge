class Solution {
public:
    void fun(vector<int>&res, int n){
        if(n==0)
            return;
        if(n==1){
            res.push_back(0);
            res.push_back(1);
            return;
        }
        fun(res,n-1);
        int size=res.size();
        for(int i=size-1;i>=0;i--)
            res.push_back((res.at(i)<<1)+1);
        
        for(int i=0;i<size;i++)
            res[i]=(res.at(i)<<1);
    }
    vector<int> grayCode(int n) {
        vector<int>res;
        fun(res,n);
        return res;
    
    
    }

};