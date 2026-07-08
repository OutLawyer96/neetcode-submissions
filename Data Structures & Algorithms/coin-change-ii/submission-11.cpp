class Solution {
public:
    int counter(vector<int>& coins, int target, int i,vector<vector<int>>& dp){
        if(target==0){
            return 1;
        }
        if(i>=coins.size() ){
            return 0;
        }
        if(dp[target][i]!=-1){
            return dp[target][i];
        }
        int count=0;
        if(target>=coins[i]){
            count+=counter(coins,target-coins[i],i,dp);
            count+=counter(coins,target,i+1,dp);
        }
        dp[target][i]=count;
        return count;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1,vector<int> (coins.size(),-1));
        sort(coins.begin(),coins.end());
        dp[0]=vector<int> (coins.size(),1);
        return counter(coins,amount,0,dp);
    }
};
