class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int carry=0,dig=0;
        vector<int>res;
        int n=digits.size();
         res.push_back((digits[n-1]+1)%10);
         carry=(digits[n-1]+1)/10;
     for(int i=n-2;i>=0;i--){
         res.push_back((digits[i]+carry)%10);
         carry=(digits[i]+carry)/10;
     }
        if(carry!=0)
            res.push_back(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};
