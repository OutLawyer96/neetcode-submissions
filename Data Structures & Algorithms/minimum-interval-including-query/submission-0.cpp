class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(),intervals.end());
        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        int j=0;
        vector<int> res(queries.size());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<queries.size();i++){
            while(j<intervals.size() && intervals[j][0]<=q[i].first){
                pq.push({intervals[j][1]-intervals[j][0]+1,intervals[j][1]});
                j++;
            }
            while(!pq.empty() && pq.top().second<q[i].first){
                pq.pop();
            }
            if(pq.empty()){
                res[q[i].second]=-1;
            }else{
                res[q[i].second]=pq.top().first;
            }
        }
        return res;
    }
};
