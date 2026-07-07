class Solution {
public:
    int currprof(int i,int buy, vector<int>& prices,vector<vector<int>>& dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int profit=0;
        if(buy){
            profit=max(currprof(i+1,0,prices,dp)-prices[i],currprof(i+1,1,prices,dp));
        }else{
            profit=max(currprof(i+2,1,prices,dp)+prices[i],currprof(i+1,0,prices,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int> (2,-1));
        currprof(0,1,prices,dp);
        return dp[0][1];
    }
};
