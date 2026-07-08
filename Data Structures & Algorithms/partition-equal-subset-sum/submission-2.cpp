class Solution {
public:
    bool check(vector<int>& nums,int target,int lsum,int i,int k,vector<vector<int>>& dp){
        if(i==nums.size()){
            if(lsum==target){
                return true;
            }else{
                return false;
            }
        }
        if(dp[i][lsum]!=-1){
            return dp[i][lsum];
        }else{
            if(check(nums,target,lsum+nums[i],i+1,k,dp) or check(nums,target,lsum,i+1,k,dp)){
                dp[i][lsum]=1;
                return true;
            }else{
                dp[i][lsum]=0;
                return false;
            }
        }
    }
    bool canPartition(vector<int>& nums) {
        int n=accumulate(nums.begin(),nums.end(),0);
        int target=n/2;
        if(n%2!=0){
            return false;
        }
        vector<vector<int>> dp(nums.size(),vector<int> (n,-1));
        return check(nums,target,0,0,n,dp);
    }
};
