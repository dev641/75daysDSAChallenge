// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int s=arr.size();
        // vector<vector<bool>>tbl(s+1,vector<bool>(sum+1));
        bool tbl[s+1][sum+1];
         for(int i=0;i<sum+1;i++){
            tbl[0][i]=false;
        }
        
        for(int i=0;i<s+1;i++){
            tbl[i][0]=true;
        }
       
        for(int i=1;i<s+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1]<=j){
                    tbl[i][j]=tbl[i-1][j] || tbl[i-1][j-arr[i-1]];
                }
                else{
                    tbl[i][j]=tbl[i-1][j];
                }
            }
        }
        return tbl[s][sum];
   
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends