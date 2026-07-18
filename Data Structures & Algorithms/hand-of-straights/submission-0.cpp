class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(),hand.end());
        if(hand.size()%groupSize!=0){
            return false;
        }
        int n=hand.size()/groupSize;
        vector<vector<int>> card(n);
        for(int i=0;i<hand.size();i++){
            for(int j=0;j<n;j++){
                if(card[j].empty()){
                    card[j].push_back(hand[i]);
                    break;
                }
                if(card[j].size()!=groupSize && card[j].back()==hand[i]-1){
                    card[j].push_back(hand[i]);
                    break;
                }
                if(j==n-1){
                    return false;
                }
            }
        }
        return true;
    }
};
