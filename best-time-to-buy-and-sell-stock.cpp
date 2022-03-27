class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cp=prices[0],sp,curr=0;
        for(int i=1;i<prices.size();i++){
            sp=prices[i];
            if(sp<cp)
            {
                cp=sp;
            }
            else{
                curr=max(curr,sp-cp);
                
            }
        }
        return curr;
    }
};
