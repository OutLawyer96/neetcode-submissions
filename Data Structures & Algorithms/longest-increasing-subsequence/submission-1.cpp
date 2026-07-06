class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        dp[0]=1;
        int ans=1;
        for(int i=1;i<nums.size();i++){
            int maxi=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    maxi=max(maxi,dp[j]+1);
                }
            }
            dp[i]=maxi;
            ans=max(dp[i],ans);
        }
        return ans;
    }
};
