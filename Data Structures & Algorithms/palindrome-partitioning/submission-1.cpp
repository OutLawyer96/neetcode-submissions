class Solution {
public:
    bool pal(string s){
        string r=s;
        reverse(r.begin(),r.end());
        return r==s;
    }
    void dfs(string s,vector<vector<string>>& res,vector<string>& subset,int c,int k){
        string curr=s.substr(c,k-c);
        if(k==s.length() && pal(curr)){
            subset.push_back(curr);
            res.push_back(subset);
            subset.pop_back();
            return;
        }else if(k==s.length()){
            return;
        }
        if(pal(curr)){
            subset.push_back(curr);
            dfs(s,res,subset,k,k+1);
            subset.pop_back();
        }
        dfs(s,res,subset,c,k+1);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> subset;
        dfs(s,res,subset,0,1);
        return res;
    }
};
