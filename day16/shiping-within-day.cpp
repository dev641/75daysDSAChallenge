class Solution {
public:
    bool possibleSol(vector<int>weights,int mid,int days){
        int count=0,sum=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]>mid||count>days)
                return false;
            if(sum+weights[i]>mid){
                sum=weights[i];
                count++;
            }
            else sum+=weights[i];
        }
        return count<days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0;
        for(int i=0;i<weights.size();i++)
            sum+=weights[i];
        int maxi=weights[0];
        for(int i=1;i<weights.size();i++){
            maxi=max(weights[i],maxi);
        }
        
        int l=maxi,h=sum;
        int res=sum;
        while(l<h){
            int mid=(l+h)/2;
            if(possibleSol(weights,mid,days))
            {
                res=mid;
                h=mid;
            }
            else l=mid+1;
        }
        return res;
    }
};