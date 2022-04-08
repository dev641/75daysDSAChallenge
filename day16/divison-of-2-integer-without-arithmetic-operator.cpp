class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==1<<31 and divisor==-1)
            return INT_MAX;
       bool isResNeg=(dividend<0)^(divisor<0)? true:false;
       long int absdividend=abs(dividend);
       long int absdivisor=abs(divisor);
       long int res=0;
        while(absdividend-absdivisor>=0){  
            int count=0;
            while(absdividend-(absdivisor<<1<<count) >=0){
               count++;
            }
            res+=1<<count;
            absdividend-=absdivisor<<count;
        }
        return !isResNeg?res:~res+1;  
    }
};




// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         bool isNeg=(dividend<0)^(divisor<0)? true:false;
//         int absdividend=abs(dividend);
//         int absdivisor=abs(divisor);
//         int res=0;
//         while(absdividend-absdivisor>=0){
//             int tmp=absdivisor;
//             int quotient=1;
//             while(absdividend-tmp>=0){
//                 tmp<<=1;
//                 quotient<<=1;
//             }
//             res+=quotient>>1;
//             absdividend-=tmp>>1;
//         }
//         if(isNeg==true)
//             return ~res+1;
//         else if(res==INT_MAX)
//             return INT_MAX;
//         else return res; 
//     }
// };
// class Solution2 {
// public:
//     int divide(int dividend, int divisor) {
//                 if(dividend==1<<31 and divisor==-1)
//             return INT_MAX;
//         bool isResNeg=(dividend<0)^(divisor<0)? true:false;
//         int absdividend=abs(dividend);
//         int absdivisor=abs(divisor);
//         int res=0;
//         while(absdividend-absdivisor>=0){  
//             int count=0;
//             while(absdividend-(absdivisor<<1<<count) >=0){
//                count++;
//             }
//             res+=1<<count;
//             absdividend-=absdivisor<<count;
//         }
//         return !isResNeg?res:~res+1;
//     }
// };
