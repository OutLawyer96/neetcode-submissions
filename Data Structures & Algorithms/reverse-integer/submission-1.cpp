class Solution {
public:
    int reverse(int x) {
        int ans=0;
        int check1=INT_MAX/10;
        int check2=INT_MIN/10;
        while(x!=0){
            if(ans>check1 || ans<check2){
                return 0;
            }
            ans*=10;
            ans+=x%10;
            x/=10;
        }
        return ans;
    }
};
