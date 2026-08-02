class Solution {
public:
    void dfs(unordered_map<string,vector<string>>& adjlist,const string& curr,stack<string>& res){
        while(!adjlist[curr].empty()){
            string dest=adjlist[curr].back();
            adjlist[curr].pop_back();
            dfs(adjlist,dest,res);
        }
        res.push(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.rbegin(),tickets.rend());
        unordered_map<string,vector<string>> adjlist;
        for(const auto& ticket:tickets){
            adjlist[ticket[0]].push_back(ticket[1]);
        }
        vector<string> res;
        string k="JFK";
        stack<string> st;
        dfs(adjlist,k,st);
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};
