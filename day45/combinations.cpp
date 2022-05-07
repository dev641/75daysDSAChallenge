class Solution {
public:

    void fun(int i,int k,int n,vector<int>&v,vector<vector<int>>&res){
         // v.push_back(i);
        if(v.size()==k)
        {
            res.push_back(v);
            return ;
        }
        for(int j=i;j<=n;j++){
            swap(i,j);
            v.push_back(i);
            fun(i+1,k,n,v,res);
            v.pop_back();
            swap(i,j);
        }
      
        // for(int j=i+1;j<=n;j++)
        //     fun(j,k,n,v,res);
        // v.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
         vector<vector<int>>res;
         vector<int>v;
         fun(1,k,n,v,res);
        // for(int i=1;i<=n;i++)
        //     fun(i,k,n,v,res);
         return res;
    }
};