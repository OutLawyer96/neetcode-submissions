class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()>s.length()){
            return "";
        }
        int have=0;
        unordered_map<char,int> sub;
        unordered_map<char,int> cur;
        for(char c: t){
            sub[c]++;
        }
        int l=0,mini=s.length()+1;
        string res="";
        for(int r=0;r<s.length();r++){
            if(sub.count( s[r] )){
                cur[s[r]]++;
                if(cur[s[r]]<=sub[s[r]]){
                    have++;
                }
            }
            while(have==t.length()){
                if(sub.count(s[l])){
                    cur[s[l]]--;
                    if(cur[s[l]]<sub[s[l]]){
                        if(mini>r-l+1){
                            mini=min(mini,r-l+1);
                            res=s.substr(l,r-l+1);
                        }
                        have--;
                    }
                }
                l++;
            }
        }
        return res;
    }
};