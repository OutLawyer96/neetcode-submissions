class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjlist(n+1);
        for(int i=0;i<times.size();i++){
            adjlist[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            int topdist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(topdist>dist[node]){
                continue;
            }
            for(auto time: adjlist[node]){
                    if(topdist+time.second<dist[time.first]){
                        dist[time.first]=topdist+time.second;
                        pq.push({topdist+time.second,time.first});
                    }
            }
        }
        int ans=0;
        for(int i=1;i<n+1;i++){
            if(dist[i]==1e9){
                return -1;
            }
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};
