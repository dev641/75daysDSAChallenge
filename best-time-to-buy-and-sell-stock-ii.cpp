class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0;
        int cp=prices[0],sp;
        for(int i=1;i<prices.size();i++){
            sp=prices[i];
            if(cp<sp){
                maxprofit+=(sp-cp);
                cp=sp;
            }
            else{
                cp=sp;
            }
        }
        return maxprofit;
    }
};
