class DSU{
    public:
    vector<int> rank,par;

    DSU(int n){
        rank.resize(n+1,0);
        par.resize(n+1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }

    int findpar(int i){
        if(i==par[i]){
            return i;
        }
        return par[i]=findpar(par[i]);
    }

    bool unite(int a,int b){
        int ua=findpar(a);
        int ub=findpar(b);
        if(ua==ub){
            return false;
        }
        if(rank[ua]>rank[ub]){
            par[ub]=ua;
        }else if(rank[ua]<rank[ub]){
            par[ua]=ub;
        }else{
            par[ua]=ub;
            rank[ub]++;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        vector<int> ans;
        for(int i=0;i<edges.size();i++){
            if(!dsu.unite(edges[i][0],edges[i][1])){
                ans= edges[i];
            }
        }
        return ans;
    }
};
