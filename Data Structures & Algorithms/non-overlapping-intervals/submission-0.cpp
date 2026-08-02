class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans=0;
        int prevend=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<prevend){
                ans++;
                prevend=min(intervals[i][1],prevend);
            }else{
                prevend=intervals[i][1];
            }
        }
        return ans;
    }
};
