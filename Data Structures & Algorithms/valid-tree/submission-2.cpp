class Solution {
public:
    bool check(vector<vector<int>>& adjlist,int i,int p,vector<int>& visited){
        visited[i]=1;
        for(int k=0;k<adjlist[i].size();k++){
            if(adjlist[i][k]==p){
                continue;
            }
            if(visited[adjlist[i][k]]==1){
                return true;
            }
            if(check(adjlist,adjlist[i][k],i,visited)){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1){
            return false;
        }
        vector<int> visited(n,0);
        vector<vector<int>> adjlist(n);
        for(int i=0;i<edges.size();i++){
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }
        if(check(adjlist,0,-1,visited)){
            return false;
        }
        for(int i=1;i<n;i++){
            if(visited[i]!=1){
                return false;
            }
        }
        return true;
    }
};
