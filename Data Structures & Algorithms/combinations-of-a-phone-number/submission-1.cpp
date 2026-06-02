class Solution {
public:
    void dfs(int i,string digits,string curr,vector<string>& res){
        if(i==digits.length()){
            res.push_back(curr);
            return;
        }
        if(digits[i]=='2'){
            string t="abc";
            for(int k=0;k<3;k++){
                string g=curr+t[k];
                dfs(i+1,digits,g,res);
            }
        }
        if(digits[i]=='3'){
            string t="def";
            for(int k=0;k<3;k++){
                string g=curr+t[k];
                dfs(i+1,digits,g,res);
            }
        }
        if(digits[i]=='4'){
            string t="ghi";
            for(int k=0;k<3;k++){
                string g=curr+t[k];
                dfs(i+1,digits,g,res);
            }
        }
        if(digits[i]=='5'){
            string t="jkl";
            for(int k=0;k<3;k++){
                string g=curr+t[k];
                dfs(i+1,digits,g,res);
            }
        }
        if(digits[i]=='6'){
            string t="mno";
            for(int k=0;k<3;k++){
                string g=curr+t[k];
                dfs(i+1,digits,g,res);
            }
        }
        if(digits[i]=='7'){
            string t="pqrs";
            for(int k=0;k<4;k++){
                string g=curr+t[k];
                dfs(i+1,digits,g,res);
            }
        }
        if(digits[i]=='8'){
            string t="tuv";
            for(int k=0;k<3;k++){
                string g=curr+t[k];
                dfs(i+1,digits,g,res);
            }
        }
        if(digits[i]=='9'){
            string t="wxyz";
            for(int k=0;k<4;k++){
                string g=curr+t[k];
                dfs(i+1,digits,g,res);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.length()==0){
            return res;
        }
        string curr="";
        dfs(0,digits,curr,res);
        return res;
    }
};
