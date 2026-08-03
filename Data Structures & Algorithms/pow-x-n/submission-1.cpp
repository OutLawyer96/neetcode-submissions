class Solution {
public:
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        if(n==1){
            return x;
        }
        if(n>0){
            double half=myPow(x,n/2);
            if(n%2==0){
                return half*half;
            }else{
                return half*half*x;
            }
        }else{
            return myPow(1/x,n*-1);
        }
    }
};
