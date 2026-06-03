class Solution {
public:
    bool checker(int k,int n,vector<vector<int>>& board){
        vector<int> visited(n,0);
        for(int i=0;i<=k;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==1){
                    if(visited[j]==1){
                        return false;
                    }
                    visited[j]=1;
                    int l=i;
                    for(int c=1;c<n-i;c++){
                        if(l+c<n && j+c<n && board[l+c][j+c]==1){
                            return false;
                        }if(l+c<n && j-c>=0 && board[l+c][j-c]==1){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
    void dfs(int i,int n,vector<string>& curr,vector<vector<int>>& board,vector<vector<string>>& res){
        if(i==n){
            res.push_back(curr);
            return;
        }
        for(int j=0;j<n;j++){
            board[i][j]=1;
            if(checker(i,n,board)){
                string s="";
                for(int k=0;k<n;k++){
                    if(k==j){
                        s+='Q';
                    }else{
                        s+='.';
                    }
                }
                curr.push_back(s);
                dfs(i+1,n,curr,board,res);
                curr.pop_back();
            }
            board[i][j]=0;
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<vector<int>> board(n,vector<int>(n,0));
        vector<string> curr;
        dfs(0,n,curr,board,res);
        return  res;
    }
};
