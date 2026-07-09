class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int> spd;
        for(int i=0;i<speed.size();i++){
            if(spd[position[i]]){
                spd[position[i]]=min(spd[position[i]],speed[i]);
            }
            else{
                spd[position[i]]=speed[i];
            }
        }
        sort(position.rbegin(),position.rend());
        float time=0;
        int count=0;
        float leader=0;
        for(int i=0;i<position.size();i++){
            time=(float)(target-position[i])/spd[position[i]];
            if(time>leader){
                count++;
                leader=time;
            }
        }
        return count;
    }
};
