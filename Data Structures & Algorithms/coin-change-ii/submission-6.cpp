class Solution {
public:
    int counter(vector<int>& coins, int target, int i,vector<vector<int>>& dp){
        if(target==0){
            return 1;
        }
        int count=0;
        for(int j=i;j<coins.size();j++){
            if(target-coins[j]<0){
                continue;
            }else{
                if(dp[target-coins[j]][j]!=-1){
                    count+=dp[target-coins[j]][j];
                }else{
                    count+=dp[target-coins[j]][j]=counter(coins,target-coins[j],j,dp);
                }
            }
        }
        return count;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1,vector<int> (coins.size(),-1));
        dp[0]=vector<int> (coins.size(),1);
        return counter(coins,amount,0,dp);
    }
};
