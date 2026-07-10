class Solution {
public:
    int finder(vector<int>& nums,int l,int r,vector<vector<int>>& dp){
        if(r<l){
            return 0;
        }
        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int maxi=0;
        for(int k=l;k<r+1;k++){
            maxi=max(maxi,finder(nums,l,k-1,dp)+nums[l-1]*nums[k]*nums[r+1]+finder(nums,k+1,r,dp));
        }
        dp[l][r]=maxi;
        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size()+1,vector<int> (nums.size()+1,-1));
        return finder(nums,1,nums.size()-2,dp);
    }
};
