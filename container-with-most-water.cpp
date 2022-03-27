class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea=INT_MIN;
        int i=0,j=height.size()-1;
        while(i<j){
            int area;
            if(height[i]<height[j]){
                area=height[i]*(j-i);
                maxArea=max(maxArea,area);
                i++;
            }
            else{
                area=height[j]*(j-i);
                maxArea=max(maxArea,area);
                j--;
            }
            
        }
        return maxArea;
    }
};