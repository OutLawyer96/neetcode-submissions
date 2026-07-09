class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<int> track;
        track.push(0);
        for(int i=1;i<temperatures.size();i++){
            while(!track.empty() && temperatures[track.top()]<temperatures[i]){
                res[track.top()]=i-track.top();
                track.pop();
            }
            track.push(i);
        }
        return res;
    }
};
