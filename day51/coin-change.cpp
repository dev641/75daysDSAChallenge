class Solution {
public:
    pair<int,int>fun(int amount, int x){
        pair<int,int>p={amount%x,amount/x};
        return p;
    }
    int coinChange(vector<int>& coins, int amount) {
        // sort(coins.begin(),coins.end(),greater<int>());
        // int res=0;
        // for(int i=0;i<coins.size();i++){
        //     if(i==coins.size()-1)
        //     {
        //         pair<int,int>p=fun(amount,coins[i]);
        //         amount=p.first,res+=p.second;
        //         if(amount>0)
        //             return -1;    
        //     }
        //     if(amount>0){
        //         pair<int,int>p=fun(amount,coins[i]);
        //         amount=p.first,res+=p.second;
        //     }
        //     else {
        //         break;
        //     }
        // }
        // return res;
        vector<int>table(amount+1,amount+1);
        table[0]=0;
        for(int i=1;i<amount+1;i++){
            for(int coin:coins){
                if(coin<=i)
                        table[i]=min(table[i],1+table[i-coin]);
            }
        }
        
        return table[amount]==amount+1?-1:table[amount];
    }
};