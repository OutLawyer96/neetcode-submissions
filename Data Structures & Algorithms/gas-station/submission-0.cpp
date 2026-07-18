class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tgas=0;
        int tcost=0;
        int start=0;
        int curr=0;
        for(int i=0;i<gas.size();i++){
            tgas+=gas[i];
            tcost+=cost[i];
            curr+=gas[i];
            curr-=cost[i];
            if(curr<0){
                start=i+1;
                curr=0;
            }
        }
        if(tgas<tcost){
            return -1;
        }else{
            return start;
        }
    }
};
