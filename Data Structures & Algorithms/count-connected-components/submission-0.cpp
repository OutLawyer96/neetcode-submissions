class Solution {
public:
    void dfs(vector<vector<int>>& adjlist,int i,int p,vector<int>& visited){
        visited[i]=1;
        for(int k=0;k<adjlist[i].size();k++){
            if(adjlist[i][k]!=p){
                if(visited[adjlist[i][k]]==0){
                    dfs(adjlist,adjlist[i][k],i,visited);
                }
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,0);
        vector<vector<int>> adjlist(n);
        for(int i=0;i<edges.size();i++){
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                dfs(adjlist,i,-1,visited);
                count++;
            }
        }
        return count;
    }
};
