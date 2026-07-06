class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            int min=-1;
            for(int j=0;j<coins.size();j++){
                if(i-coins[j]>=0 && dp[i-coins[j]]!=-1){
                    if(min==-1 ){
                        min=dp[i-coins[j]];
                    }else{
                        if(min>dp[i-coins[j]]){
                            min=dp[i-coins[j]];
                        }
                    }
                }
            }
            if(min==-1){
                dp[i]=-1;
            }else{
                dp[i]=min+1;
            }
        }
        return dp[amount];
    }
};
