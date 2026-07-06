class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0'){
            return 0;
        }
        int prev1=1;
        int prev2=1;
        for (int i =1;i<s.length();i++){
            int curr=0;
            if(s[i]!='0'){
                curr+=prev2;}
                if(i>=1){
                    if(s.substr(i-1,2)>="10" && s.substr(i-1,2)<"27"){
                        curr+=prev1;
                    }
                }
            prev1=prev2;
            prev2=curr;
        }
        return prev2;
    }
};
