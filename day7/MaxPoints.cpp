class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int i=0,n=cardPoints.size(),j=n-k;
        int tpoints=0;
        // int i;
        for(i=0;i<k;i++)
            tpoints+=cardPoints[i];
        int ans=tpoints;
         i=0;
        while(i<k){
              tpoints+=(cardPoints[n-1-i]-cardPoints[k-i-1]);
            ans=max(ans,tpoints);
          i++;
        }
        return ans;
    }
};