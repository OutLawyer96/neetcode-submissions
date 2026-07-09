class Solution {
public:
    void backtrack(int n,int open ,int close,string& t,vector<string>& res){
        if(open+close==n*2){
            res.push_back(t);
            return;
        }
        if(open<n){
            t+="(";
            backtrack(n,open+1,close,t,res);
            t.pop_back();
            
        }
        if(close<open){
            t+=")";
            backtrack(n,open,close+1,t,res);
            t.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string t="";
        backtrack(n,0,0,t,res);
        return res;
    }
};
