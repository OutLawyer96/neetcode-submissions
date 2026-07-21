class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<int> visited(points.size(),0);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int wt=it.first;
            int dest=it.second;
            if(visited[dest]==1) continue;
            visited[dest]=1;
            sum+=wt;
            for(int i=0;i<points.size();i++){
                pq.push({abs(points[i][0]-points[dest][0])+abs(points[i][1]-points[dest][1]),i});
            }
        }
        return sum;
    }
};
