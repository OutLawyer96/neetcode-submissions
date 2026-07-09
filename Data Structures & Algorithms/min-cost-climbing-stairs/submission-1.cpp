class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> paid(n,0);
        paid[0]=cost[0];
        paid[1]=cost[1];
        for(int i=2;i<n;i++){
            int mini=paid[i-1]<paid[i-2]?paid[i-1]:paid[i-2];
            paid[i]=cost[i]+mini;
        }
        return paid[n-1]>paid[n-2]?paid[n-2]:paid[n-1];
    }
};
