class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.length(),false);
        for(int i=0;i<s.length();i++){
            if(i==0||dp[i-1]==true){
                for(string word: wordDict){
                    for(int j=0;j<word.length();j++){
                        if(i+word.length()-1>=s.length() || s[i+j]!=word[j]){
                            break;
                        }
                        if(j==word.length()-1){
                            dp[i+j]=true;
                        }
                    }
                }
            }
        }
        return dp[s.length()-1];
    }
};
