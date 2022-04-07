#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findrow(vector<vector<int>>& matrix, int target){
        int top=0,down=matrix.size()-1;
        int mid=(top+down)/2;
        if(matrix[0][0]>target||matrix[down][matrix[0].size()-1]<target)
            return -1;
        while(top<=down){
           mid=(top+down)/2;
            if(matrix[mid][0]==target)
                return mid;
           if(matrix[mid][0]>target)
            {
                down=mid-1;
                
            }
            else {
                top=mid+1;
            }
        }
        mid=matrix[mid][0]>target?mid-1:mid;
        return mid;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int row=findrow(matrix,target);
        if(row==-1)
            return false;
       int l=0,h=matrix[0].size()-1;
        bool ans=false;
        while(l<=h){
            int mid=(l+h)/2;
            if(matrix[row][mid]==target)
                ans= true;
            if(matrix[row][mid]>target)
                h=mid-1;
            else l=mid+1;
        }
        return ans;
    }
};
int main(){
int n,m,tar;
cin>>n>>m>>tar;
vector<vector<int>>matrix(n,vector<int>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
    cin>>matrix[i][j];
}
Solution ob;
bool res=ob.searchMatrix(matrix,tar);
cout<<res;
return 0;
}