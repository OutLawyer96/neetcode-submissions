class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,vector<int>& visited,int c,int i,int j){
        if(c==word.length()){
            return true;
        }
        if(i-1>=0 && visited[(i-1)*board[0].size()+j]==0 && board[i-1][j]==word[c]){
            visited[(i-1)*board[0].size()+j]=1;
            if(dfs(board,word,visited,c+1,i-1,j)){
                return true;
            }
            visited[(i-1)*board[0].size()+j]=0;
        }
        if(i+1<board.size() && visited[(i+1)*board[0].size()+j]==0 && board[i+1][j]==word[c]){
            visited[(i+1)*board[0].size()+j]=1;
            if(dfs(board,word,visited,c+1,i+1,j)){
                return true;
            }
            visited[(i+1)*board[0].size()+j]=0;
        }
        if(j-1>=0 && visited[(i)*board[0].size()+j-1]==0 && board[i][j-1]==word[c]){
            visited[(i)*board[0].size()+j-1]=1;
            if(dfs(board,word,visited,c+1,i,j-1)){
                return true;
            }
            visited[(i)*board[0].size()+j-1]=0;
        }
        if(j+1<board[0].size() && visited[(i)*board[0].size()+j+1]==0 && board[i][j+1]==word[c]){
            visited[(i)*board[0].size()+j+1]=1;
            if(dfs(board,word,visited,c+1,i,j+1)){
                return true;
            }
            visited[(i)*board[0].size()+j+1]=0;
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> visited(board.size()*board[0].size(),0);
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    visited[i*board[0].size()+j]=1;
                    if(dfs(board,word,visited,1,i,j)){
                        return true;
                    }
                    visited[i*board[0].size()+j]=0;
                }
            }
        }
        return false;
    }
};
