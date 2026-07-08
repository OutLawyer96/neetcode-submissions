class Solution {
public:
    bool checker(string& s1,string& s2,string& s3 ,int i,int j,int curr,vector<vector<int>>& dp){
        if(curr==s3.length()){
            return true;
        }
        if(dp[i][curr]!=-1){
            return dp[i][curr];
        }
        bool value=false;
        if(i!=s1.length()){
            if(s1[i]==s3[curr]){
                value= value or checker(s1,s2,s3,i+1,j,curr+1,dp);
            }
        }
        if(j!=s2.length()){
            if(s2[j]==s3[curr]){
                value=value or checker(s1,s2,s3,i,j+1,curr+1,dp);
            }
        }
        if(value){
            dp[i][curr]=1;
        }else{
            dp[i][curr]=0;
        }
        return value;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()){
            return false;
        }
        vector<vector<int>> dp(s1.length()+1,vector<int> (s3.length()+1,-1));
        return checker(s1,s2,s3,0,0,0,dp);
    }
};
