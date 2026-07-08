class Solution {
public:
    int counter(vector<int>& coins, int target, int i,vector<vector<int>>& dp){
        if(target==0){
            return 1;
        }
        int count=0;
        if(target-coins[i]<0  ){
            return 0;
        }else{
            if(dp[target-coins[i]][i]!=-1){
                count+=dp[target-coins[i]][i];
            }else{
                count+=dp[target-coins[i]][i]=counter(coins,target-coins[i],i,dp);
                
            }
            if(i+1<coins.size()){   
                count+=dp[target][i+1]=counter(coins,target,i+1,dp);
            }
        }
        return count;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1,vector<int> (coins.size(),-1));
        sort(coins.begin(),coins.end());
        dp[0]=vector<int> (coins.size(),1);
        return counter(coins,amount,0,dp);
    }
};
