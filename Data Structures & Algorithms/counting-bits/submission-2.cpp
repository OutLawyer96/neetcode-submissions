class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        vector<int> dp(n+1,-1);
        dp[0]=0;
        res.push_back(0);
        for(int i=1;i<=n;i++){
            int ans=1+dp[i&(i-1)];
            dp[i]=ans;
            res.push_back(ans);
        }
        return res;
    }
};
