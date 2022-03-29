#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int count(int i,int j,vector<vector<int>>board){
        int count=0;
        // board[i-1][j-1]+board[i-1][j]+board[i-1][j+1];
        // +board[i][j-1]+board[i+1][j-1]
        if(board.size()==1){
             if(j==0)
                  return board[i][j+1];
            else if(j==board[0].size()-1)
                 return board[i][j-1];
            else return board[0][j-1]+board[0][j+1];
        }
         if(board[0].size()==1){
             if(i==0)
                  return board[i+1][0];
            else if(i==board.size()-1)
                 return board[i-1][0];
            else return board[i+1][0]+board[i-1][0];
        }
                                            
        if(i==0 and j==0)
        {
            count+=+board[i][j+1]+board[i+1][j]+board[i+1][j+1];
            
        }
        else if(i==0 and j==board[0].size()-1)
        {
             count+=+board[i][j-1]+board[i+1][j]+board[i+1][j-1];
        }
        else if(i==board.size()-1 and j==0)
        {
             count+=+board[i-1][j]+board[i-1][j+1]+board[i][j+1];
        }
         else if(i==board.size()-1 and j==board[0].size()-1)
        {
             count+=+board[i][j-1]+board[i-1][j-1]+board[i-1][j];
        }
        else if(i==0){
            count+=board[i][j-1]+board[i+1][j-1]+board[i+1][j]+board[i+1][j+1]+board[i][j+1];
        }
        else if(i==board.size()-1){
            count+=board[i][j-1]+board[i-1][j-1]+board[i-1][j]+board[i-1][j+1]+board[i][j+1];
        }
         else if(j==0){
            count+=board[i-1][j]+board[i-1][j+1]+board[i][j+1]+board[i+1][j+1]+board[i+1][j];
        }
         else if(j==board[0].size()-1){
            count+=board[i-1][j]+board[i-1][j-1]+board[i][j-1]+board[i+1][j-1]+board[i+1][j];
        }
         else {
            count+=board[i-1][j]+board[i-1][j-1]+board[i][j-1]+board[i+1][j-1]+board[i+1][j]+board[i+1][j+1]+board[i][j+1]+board[i-1][j+1];
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>>res=board;
        if(board.size()==1 and board[0].size()==1)
        {
            board[0][0]=0;
            return ;
        }
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int cnt=count(i,j,board);
                if(board[i][j]==1 and cnt<2)
                    res[i][j]=0;
                else if(board[i][j]==1 and (cnt==2 || cnt==3))
                    res[i][j]=1;
                else if(board[i][j]==1 and cnt>3)
                    res[i][j]=0;
                else if(board[i][j]==0 and cnt==3)
                    res[i][j]=1;
                
            }
        }
        board=res;
    }
};
int main(){
int n,m;
cin>>n>>m;
vector<vector<int>>board(n,vector<int>(m));
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
     cin>>board[i][j];
}
Solution ob;
ob.gameOfLife(board);
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)
     cout<<board[i][j]<<" ";
     cout<<endl;
}
return 0;
}