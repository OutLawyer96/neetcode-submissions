class Solution {

public:
    int dp(int n){
        if(n==1){
            return 1;
        }else if(n==2){
            return 2;
        }else{
            return dp(n-1)+dp(n-2);
        }
    }
    int climbStairs(int n) {
        return dp(n);
    }
};
