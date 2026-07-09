class Solution {
public:
    int finder(string& word1,string& word2,int i,int j,vector<vector<int>>& dp){
        if(j==word2.length()){
            dp[i][j]=word1.length()-i;
            return word1.length()-i;
        }
        int curr=0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i==word1.length()){
            curr=1+finder(word1,word2,i,j+1,dp);
        }else if(word1[i]!=word2[j]){
            curr=1+finder(word1,word2,i+1,j,dp);
            curr=min(curr,1+finder(word1,word2,i+1,j+1,dp));
            curr=min(curr,1+finder(word1,word2,i,j+1,dp));
        }else{
            curr=finder(word1,word2,i+1,j+1,dp);
        }
        dp[i][j]=curr;
        return curr;
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1,vector<int> (word2.length()+1,-1));
        return finder(word1,word2,0,0,dp);
    }
};
