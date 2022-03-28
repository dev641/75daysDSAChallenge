#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0,left=0,right=matrix[0].size()-1,down=matrix.size()-1;
        vector<int>res;
        // vector<char>dir={l,r,t,b};
         int i=0;
         int n=(right+1)*(down+1);
        while(i<n){ 
            if(i>=n)
              break;
        for(int j=left;j<=right;j++){
            if(i>=n)
              break;
            res.push_back(matrix[top][j]);
            i++;
        }
        top++;
        
        if(i>=n)
              break;
        for(int j=top;j<=down;j++){
            if(i>=n)
              break;
          res.push_back(matrix[j][right]);
            i++;
      }
        right--;
        if(i>=n)
              break;
      for(int j=right;j>=left;j--){
          if(i>=n)
              break;
          res.push_back(matrix[down][j]);
          i++;
      }        
    down--;
    if(i>=n)
              break;
        for(int j=down;j>=top;j--){
            if(i>=n)
              break;
            res.push_back(matrix[j][left]);
            i++;
        }
        left++;
    }
    
    return res;
}
};
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>matrix(n,vector<int>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
     cin>>matrix[i][j];
}
Solution ob;
vector<int>res=ob.spiralOrder(matrix);
for(auto i:res)
cout<<i<<"  ";
return 0;
}