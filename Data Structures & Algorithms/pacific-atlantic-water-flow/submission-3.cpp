class Solution {
public:
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dppaci(n,vector<int> (m,-1));
        vector<vector<int>> dpatla(n,vector<int> (m,-1));
        vector<vector<int>> res;
        queue<pair<int,int>> q;
        for(int j=0;j<m;j++){
            dppaci[0][j]=1;
            q.push({0,j});
        }
        for(int i=1;i<n;i++){
            dppaci[i][0]=1;
            q.push({i,0});
        }

        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            for(int l=0;l<4;l++){
                int ki=i+dx[l];
                int kj=j+dy[l];
                if(ki>=0 && kj>=0 && ki<n && kj<m){
                    if(dppaci[ki][kj]!=1 && heights[ki][kj]>=heights[i][j]){
                        dppaci[ki][kj]=1;
                        q.push({ki,kj});
                    }
                }
            }
        }
        
        for(int j=0;j<m;j++){
            dpatla[n-1][j]=1;
            q.push({n-1,j});
        }
        for(int i=0;i<n-1;i++){
            dpatla[i][m-1]=1;
            q.push({i,m-1});
        }

        while(!q.empty()){
            pair<int,int> p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            for(int l=0;l<4;l++){
                int ki=i+dx[l];
                int kj=j+dy[l];
                if(ki>=0 && kj>=0 && ki<n && kj<m){
                    if(dpatla[ki][kj]!=1 && heights[ki][kj]>=heights[i][j]){
                        dpatla[ki][kj]=1;
                        q.push({ki,kj});
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dppaci[i][j]==1 && dpatla[i][j]==1){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
