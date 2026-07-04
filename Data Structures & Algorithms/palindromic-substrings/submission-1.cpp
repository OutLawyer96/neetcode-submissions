class Solution {
public:
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            int j=1;
            count++;
            while(i-j>=0&& i+j<s.length()){
                if(s[i-j]==s[i+j]){
                    j++;
                    count++;
                }else{
                    break;
                }
            }

            j=1;
            while(i-j>=0&& i+j-1<s.length()){
                if(s[i-j]==s[i+j-1]){
                    j++;
                    count++;
                }else{
                    break;
                }
            }
        }
        return count;
    }
};
