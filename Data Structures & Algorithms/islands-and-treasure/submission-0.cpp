class Solution {
public:
    vector<int> dx={-1,1,0,0};
    vector<int> dy={0,0,-1,1};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int curr=1;
        while(!q.empty()){
            int sz=q.size();
            for(int k=0;k<sz;k++){
                pair<int,int> p=q.front();
                int i=p.first;
                int j=p.second;
                q.pop();
                for(int l=0;l<4;l++){
                    int li=i+dx[l];
                    int lj=j+dy[l];
                    if(li>=0 && lj>=0 && li<n && lj<m){
                        if(grid[li][lj]!=-1 && grid[li][lj]>curr){
                            grid[li][lj]=curr;
                            q.push({li,lj});
                        }
                    }
                }
            }
            curr++;
        }
    }
};
