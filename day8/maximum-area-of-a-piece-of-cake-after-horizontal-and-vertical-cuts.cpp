#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
class Solution {
public:
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int maxArea=0,currArea=0;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        // int i=0,j=0,b,l;
        // // for( l=0;l<horizontalCuts.size();l++){
        // //     for( b=0;b<verticalCuts.size();b++){
        // //         currArea=(horizontalCuts[l]-i)*(verticalCuts[b]-j);
        // //         maxArea=max(currArea,maxArea);
        // //         j=verticalCuts[b];
        // //     }
        // //     if(b==verticalCuts.size() and w!=verticalCuts[verticalCuts.size()-1])
        // //     {
        // //         currArea=(horizontalCuts[l]-i)*(w-j);
        // //         maxArea=max(currArea,maxArea);
        // //         j=0;
        // //     }
        // //     i=horizontalCuts[l];
        // // }
        // // if(l==horizontalCuts.size() and w!=horizontalCuts[horizontalCuts.size()-1])
        // //     {   int b=0;
        // //         while(b<verticalCuts.size()){
        // //             currArea=(h-i)*(verticalCuts[b]-j);
        // //         maxArea=max(currArea,maxArea);
        // //             b++;
        // //         }
        // //     }
        // // return maxArea;
        
        int maxlen=0;
        int l=0,b=0;
        for(int i=0;i<horizontalCuts.size();i++){
            maxlen=max(maxlen,abs(l-horizontalCuts[i]));
            l=horizontalCuts[i];
        }
        maxlen=max(maxlen,abs(l-h));
         int maxbr=0;
        for(int i=0;i<verticalCuts.size();i++){
            maxbr=max(maxbr,abs(b-verticalCuts[i]));
            b=verticalCuts[i];
        }
        maxbr=max(maxbr,abs(b-w));
        return (((long long)(maxbr)%m)*(long long)(maxlen%m))%m;
    }
};
int main(){
int n,m,h,b;
cin>>n>>m>>h>>b;
vector<int>v(h,0);
vector<int>v1(b,0);
for(int i=0;i<h;i++)
cin>>v[i];
for(int i=0;i<b;i++)
cin>>v1[i];
Solution ob;
int res=ob.maxArea(n,m,v,v1);
cout<<res;
return 0;
}