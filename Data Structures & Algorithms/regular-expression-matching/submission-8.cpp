class Solution {
public:
    bool matcher(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if (j == p.size()) {
            return i == s.size();
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        bool val=false;
        if (i == s.size()) {
            if (p[j] == '*') {
                val= matcher(s, p, i, j + 1,dp);
            }

            else if (j + 1 < p.size() && p[j + 1] == '*') {
                val =matcher(s, p, i, j + 1,dp);
            }
            dp[i][j]=val;
            return val;
        }

        if (j + 1 < p.size() && p[j + 1] == '*') {
            val= matcher(s, p, i, j + 1,dp);
        }

        else if (s[i] == p[j] || p[j] == '.') {
            val= matcher(s, p, i + 1, j + 1,dp);
        }
        else if (p[j] == '*') {
            bool res = false;

            res = res || matcher(s, p, i, j + 1,dp);

            if (s[i] == p[j - 1] || p[j - 1] == '.') {
                res = res || matcher(s, p, i + 1, j,dp);
            }

            val= res;
        }
        if(val){
            dp[i][j]=1;
        }else{
            dp[i][j]=0;
        }
        return val;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1,vector<int> (p.size()+1,-1));
        return matcher(s, p, 0, 0,dp);
    }
};