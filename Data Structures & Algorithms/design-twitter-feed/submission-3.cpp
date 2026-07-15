class Twitter {
public:
    int time=0;
    unordered_map<int,unordered_set<int>> following;
    unordered_map<int,vector<pair<int,int>>> tweets;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time,tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=tweets[userId].size()-1;i>=0;i--){
            if(pq.size()<10){
                pq.push(tweets[userId][i]);
            }else{
                if(tweets[userId][i].first>pq.top().first){
                    pq.push(tweets[userId][i]);
                    pq.pop();
                }else{
                    break;
                }
            }
        }
        for(auto user:following[userId]){
            for(int i=tweets[user].size()-1;i>=0;i--){
                if(pq.size()<10){
                    pq.push(tweets[user][i]);
                }else{
                    if(tweets[user][i].first>pq.top().first){
                        pq.push(tweets[user][i]);
                        pq.pop();
                    }else{
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return;
        }
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
