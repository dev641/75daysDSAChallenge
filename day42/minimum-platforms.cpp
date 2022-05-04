// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
     bool comp(pair<int,int>a,pair<int,int>b){
        return a.second<=b.first;
    }
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int min_plat=1;
    	vector <pair<int,int>> v;
        for(int i=0; i<n; i++)
            v.push_back({arr[i], dep[i]});
        sort(v.begin(), v.end());
        priority_queue <int, vector<int>, greater<int>> pq;
        pq.push(v[0].second);
        for(int i=1;i<n;i++){
            if(pq.top()<v[i].first)
             pq.pop();
            else
             min_plat++;
             
             pq.push(v[i].second);
        }
    	
    	return min_plat;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends