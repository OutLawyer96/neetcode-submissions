class Solution {
public:
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    int dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i,int j){
        int area=1;
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            if(i+dx[k]>=0 && i+dx[k]<grid.size() && j+dy[k]>=0 && j+dy[k]<grid[0].size()){
                if(grid[i+dx[k]][j+dy[k]]==1 && !visited[i+dx[k]][j+dy[k]]){
                    area+=dfs(grid,visited,i+dx[k],j+dy[k]);
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(),vector<bool> (grid[0].size(),false));
        int area=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(!visited[i][j] && grid[i][j]==1){
                    area=max(area,dfs(grid,visited,i,j));
                }
            }
        }
        return area;
    }
};
