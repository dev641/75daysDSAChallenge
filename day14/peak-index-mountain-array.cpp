class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
     int ind=0,n=arr.size();
       int l=0,h=arr.size()-1;
        while(l<=h){
            int mid=(l+h)/2;
        if((mid -1 >=0 && arr[mid] > arr[mid-1]) && (mid +1 <=n-1)&&arr[mid] > arr[mid+1])
            {
                ind=mid;
                break;
            }
            else if(arr[mid]<arr[mid+1])
                l=mid+1;
            else h=mid-1;
        }
        return ind;
      
    }
};