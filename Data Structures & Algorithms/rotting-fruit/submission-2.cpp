class Solution {
public:
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<int> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    q.push(i*grid[0].size()+j);
                }
            }
        }
        int count=-1;
        while(!q.empty()){
            int sz=q.size();
            for(int l=0;l<sz;l++){
                int val1=q.front();
                q.pop();
                int ni=val1/grid[0].size();
                int nj=val1%grid[0].size();
                for(int k=0;k<4;k++){
                    int ki=ni+dx[k];
                    int kj=nj+dy[k];
                    if(ki>=0 && ki<grid.size() && kj>=0 && kj<grid[0].size()){
                        if(grid[ki][kj]==1){
                            q.push(ki*grid[0].size()+kj);
                            grid[ki][kj]=2;
                        }
                    }
                }
            }
            count++;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(count==-1){
            return 0;
        }
        return count;
    }
};
