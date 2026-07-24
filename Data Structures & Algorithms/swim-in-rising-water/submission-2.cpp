class Solution {
public:
    bool check(vector<vector<int>>& grid,int t){
        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,-1,1};
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0]=1;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int i=curr.first;
            int j=curr.second;
            if(i==n-1 && j==m-1){
                return true;
            }
            for(int k=0;k<4;k++){
                int kx=i+dx[k];
                int ky=j+dy[k];
                if(kx>=0 && ky>=0 && kx<n && ky<m){
                    if(t>=grid[kx][ky] && visited[kx][ky]==0){
                        q.push({kx,ky});
                        visited[kx][ky]=1;
                    }
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int high=0;
        int low=max(grid[0][0],grid[n-1][m-1]);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                high=max(high,grid[i][j]);
            }
        }
        int ans=0;
        while(high>=low){
            int mid=(high+low)/2;
            if(check(grid,mid)){
                high=mid-1;
                ans=mid;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};
