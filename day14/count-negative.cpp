class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            int l=0,h=grid[i].size()-1;
            while(l<=h){
                int mid=(l+h)/2;
                if(grid[i][mid]<0)
                {
                    count+=h-mid+1;
                    h=mid-1;
                }
                else 
                    l=mid+1;
                
            }
        }
        return count;
    }
};