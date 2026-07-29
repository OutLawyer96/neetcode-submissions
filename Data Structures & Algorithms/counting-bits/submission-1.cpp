class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        vector<int> dp(n+1,-1);
        for(int i=0;i<=n;i++){
            int j=i;
            int ans=0;
            while(j!=0){
                if(dp[j]!=-1){
                    ans+=dp[j];
                    break;
                }
                j&=j-1;
                ans++;
            }
            dp[i]=ans;
            res.push_back(ans);
        }
        return res;
    }
};
