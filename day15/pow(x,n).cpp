class Solution {
public:
    double myPow(double x, int n) {
      if(n>0){
        if(n==1)
            return x;
        double res=myPow(x,n/2);
        if(n%2==0)
            return res*res;
        else return x*res*res;
      }
        else if(n==0)
            return 1;
        else{
            if(n==-1)
                return (1/x);
            double res=myPow(x,n/2);
            if(n%2==0)
            return res*res;
        else return (1/x)*res*res;
        }
    }
};