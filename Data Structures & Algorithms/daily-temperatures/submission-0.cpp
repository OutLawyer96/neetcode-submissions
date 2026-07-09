class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<int> temp;
        stack<int> track;
        temp.push(temperatures[0]);
        track.push(0);
        for(int i=0;i<temperatures.size();i++){
            while(!temp.empty() && temp.top()<temperatures[i]){
                temp.pop();
                res[track.top()]=i-track.top();
                track.pop();
            }
            temp.push(temperatures[i]);
            track.push(i);
        }
        return res;
    }
};
