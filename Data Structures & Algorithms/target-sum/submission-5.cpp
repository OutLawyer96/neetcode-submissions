class Solution {
public:
    int finder(vector<int>& nums, int target,int i,vector<vector<int>>& dp,int k,int curr){
        if(i==nums.size()){
            if(target==curr){
                return 1;
            }else{
                return 0;
            }
        }
        int ways=0;
        if(dp[k+curr][i]!=-1){
            ways+=dp[k+curr][i];
        }else{
            ways+=finder(nums,target,i+1,dp,k,curr-nums[i]);
            ways+=finder(nums,target,i+1,dp,k,curr+nums[i]);
            dp[k+curr][i]=ways;
        }
        return ways;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int k=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(2*(k+1),vector<int> (nums.size(),-1));
        return finder(nums,target,0,dp,k,0);
    }
};
