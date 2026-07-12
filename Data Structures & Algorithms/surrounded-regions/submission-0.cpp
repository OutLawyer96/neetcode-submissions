class Solution {
public:
    vector<int> dx={-1,1,0,0};
    vector<int> dy={0,0,-1,1};
    void solve(vector<vector<char>>& board) {
        queue<pair<int,int>> q;
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                q.push({i,0});
                board[i][0]='#';
            }
            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                board[i][m-1]='#';
            }
        }
        for(int j=1;j<m-1;j++){
            if(board[0][j]=='O'){
                q.push({0,j});
                board[0][j]='#';
            }
            if(board[n-1][j]=='O'){
                q.push({n-1,j});
                board[n-1][j]='#';
            }
        }
        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            for(int l=0;l<4;l++){
                int li=i+dx[l];
                int lj=j+dy[l];
                if(li>=0 && li<n && lj>=0 && lj<m){
                    if(board[li][lj]=='O'){
                        board[li][lj]='#';
                        q.push({li,lj});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};
