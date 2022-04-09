#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double fun(vector<int>a,vector<int>b){
        int m=a.size(),n=b.size();
        int total=m+n;
        int half=total/2;
        double res=0;
        int l=0,r=m-1; 
        while(true){
            int mida=(l+r)/2;
            int midb=half-mida-2;
            int aleft=(mida>=0)?a[mida]:INT_MIN;
            int aright=(mida+1<m)?a[mida+1]:INT_MAX;
            int bleft=(midb>=0)?b[midb]:INT_MIN;
            int bright=(midb+1<n)?b[midb+1]:INT_MAX;
            
            if(aleft<=bright and bleft<=aright){
                if(total%2)
                    return (double)(min(aright,bright));
               else return (max(aleft,bleft)+min(aright,bright))/2.0;
            }
            else if(aleft>bright)
                r=mida-1;
            else l=mida+1;
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        double res=(n>=m)? fun(nums1,nums2):fun(nums2,nums1);
        return res;
    }
};
int main(){
int n,m;
cin>>n>>m;
vector<int>v(n,0),v1(m,0);
for(int i=0;i<n;i++)
 cin>>v[i];
 for(int i=0;i<m;i++)
 cin>>v1[i];
 Solution ob;
 double res=ob.findMedianSortedArrays(v,v1);

cout<<res;
return 0;
}