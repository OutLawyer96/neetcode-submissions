class Solution {
public:
    string longestPalindrome(string s) {
        vector<string> dp(s.length());
        dp[0]=s[0];
        for(int i=1;i<s.length();i++){
            int j=1;
            while(i-j>=0&& i+j<s.length()){
                if(s[i-j]==s[i+j]){
                    j++;
                }else{
                    break;
                }
            }
            string curr=s.substr(i-j+1,j*2-1);
            j=1;
            while(i-j>=0&& i+j-1<s.length()){
                if(s[i-j]==s[i+j-1]){
                    j++;
                }else{
                    break;
                }
            }
            string next=s.substr(i-j+1,j*2-2);
            curr=curr.length()>next.length()?curr:next;
            dp[i]=curr.length()>dp[i-1].length()?curr:dp[i-1];
        }
        return dp[s.length()-1];
    }
};
