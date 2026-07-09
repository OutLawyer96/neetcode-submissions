class Solution {
public:
    void count(int i,int j,vector<vector<char>>& grid, vector<vector<bool>>& visited){
        visited[i][j]=true;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size()){
                if(grid[nr][nc]=='1' && !visited[nr][nc]){
                    count(nr,nc,grid,visited);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int islands=0;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count(i,j,grid,visited);
                    islands++;
                }
            }
        }
        return islands;
    }
};
