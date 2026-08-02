class Solution {
public:
    bool dfs(unordered_map<string,vector<string>>& adjlist,string& curr,vector<string>& res,int n){
        if(res.size()==n){
            return true;
        }
        if(adjlist[curr].empty()){
            return false;
        }
        for(int i=0;i<adjlist[curr].size();i++){
            string dest=adjlist[curr][i];
            res.push_back(dest);
            adjlist[curr].erase(adjlist[curr].begin()+i);
            if(dfs(adjlist,dest,res,n)){
                return true;
            }
            res.pop_back();
            adjlist[curr].insert(adjlist[curr].begin()+i,dest);
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(),tickets.end());
        unordered_map<string,vector<string>> adjlist;
        for(auto ticket:tickets){
            adjlist[ticket[0]].push_back(ticket[1]);
        }
        vector<string> res;
        string k="JFK";
        res.push_back(k);
        dfs(adjlist,k,res,tickets.size()+1);
        return res;
    }
};
