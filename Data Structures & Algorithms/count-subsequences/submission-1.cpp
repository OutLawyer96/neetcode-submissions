class Solution {
public:
    int checker(string& s,string& t,int i,int j,vector<vector<int>>& dp){
        if(j==t.length()){
            return 1;
        }
        if(i==s.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int curr=0;
        if(s[i]==t[j]){
            curr+=checker(s,t,i+1,j+1,dp);
        }
        curr+=checker(s,t,i+1,j,dp);
        dp[i][j]=curr;
        return curr;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(),vector<int> (t.length(),-1));
        return checker(s,t,0,0,dp);
    }
};
