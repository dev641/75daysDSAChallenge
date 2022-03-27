class Solution {
public:
    vector<vector<int>> generate(int numRows) {
          vector<vector<int>>res;
        res.push_back(vector<int>(1,1));
        for(int i=2;i<=numRows;i++){
            res.push_back(vector<int>(i,0));
        }
        // res[1][0]=res[1][1]=1;
        for(int i=1;i<numRows;i++){
           for(int j=0;j<=i;j++){
               if(j==0||j==i){
                   res[i][j]=1;
               }
               else
               res[i][j]=res[i-1][j-1]+res[i-1][j];
           }
        }
        return res;
    }
};