class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }
        queue<pair<int,int>> q;
        int res=0;
        while(!pq.empty() or !q.empty()){
            res++;
            if(!q.empty()){
                if(q.front().first==res){
                    pq.push(q.front().second);
                    q.pop();
                }
            }
            if(!pq.empty()){
                int k=pq.top();
                pq.pop();
                if(k>1){
                    q.push({res+n+1,k-1});
                }
            }
        }
        return res;
    }
};
