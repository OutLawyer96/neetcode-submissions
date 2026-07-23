class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<pair<char,char>> edges;
        vector<int> indegree(26,-1);
        for(char c: words[0]){
            if(indegree[c-'a']==-1){
                indegree[c-'a']=0;
            }
        }
        for(int i=1;i<words.size();i++){
            string curr=words[i];
            string prev=words[i-1];
            for(int j=0;j<curr.size();j++){
                if(indegree[curr[j]-'a']==-1){
                    indegree[curr[j]-'a']=0;
                }
            }
            for(int j=0;j<prev.size();j++){
                if(j>=curr.size()){
                    return "";
                }
                if(curr[j]!=prev[j]){
                    edges.push_back({prev[j],curr[j]});
                    break;
                }
            }
        }
        
        vector<set<char>> adjlist(26);
        for(int i=0;i<edges.size();i++){
            auto p=adjlist[edges[i].first-'a'].insert(edges[i].second);
            if(!p.second){
                continue;
            }
            if(indegree[edges[i].second-'a']!=-1){
                indegree[edges[i].second-'a']++;
            }else{
                indegree[edges[i].second-'a']=1;
            }
            if(indegree[edges[i].first-'a']==-1){
                indegree[edges[i].first-'a']=0;
            }
        }
        queue<char> q;
        int total=0;
        for(int i=0;i<26;i++){
            if(indegree[i]!=-1){
                total++;
            }
            if(indegree[i]==0){
                q.push(i+'a');
            }
        }
        string res="";
        while(!q.empty()){
            char curr=q.front();
            q.pop();
            res+=curr;
            for(auto it: adjlist[curr-'a']){
                indegree[it-'a']--;
                if(indegree[it-'a']==0){
                    q.push(it);
                }
            }
        }
        if(res.length()!=total){
            return "";
        }
        return res;
    }
};
