class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> curr={0,0,0};
        for(auto triplet: triplets){
            if(triplet[0]<=target[0] && triplet[1]<=target[1] && triplet[2]<=target[2]){
                curr={max(curr[0],triplet[0]),max(curr[1],triplet[1]),max(curr[2],triplet[2])};
            }
        }
        return curr==target;
    }
};
