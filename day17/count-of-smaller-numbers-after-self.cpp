class Solution {
public:
    void merge(vector<int>&res,vector<pair<int,int>>&v,int l ,int mid, int r){
        vector<pair<int,int>>temp(r-l+1);
        int i=l,j=mid+1,k=0;
        while(i<=mid &&j<=r){
            if(v[i].first<=v[j].first){
                temp[k++]=v[j++];
            }
            else
            {
                res[v[i].second]+=r-j+1;
                temp[k++]=v[i++];
            }
        }
        while(i<=mid)
            temp[k++]=v[i++];
        while(j<=r)
            temp[k++]=v[j++];
        for(i=l;i<=r;i++){
            v[i]=temp[i-l];
        }
    }
    void mergeSort(vector<int>&res,vector<pair<int,int>>&v,int l,int r){
        if(l<r){
            int mid=(l+r)/2;
            mergeSort(res,v,l,mid);
            mergeSort(res,v,mid+1,r);
            merge(res,v,l,mid,r);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
       vector<pair<int,int>>v(nums.size());
        for(int i=0;i<nums.size();i++){
            pair<int,int>p;
            p.first=nums[i];
            p.second=i;
            v[i]=p;
        }
        vector<int>res(nums.size());
        mergeSort(res,v,0,nums.size()-1);
        return res;
    }
};

