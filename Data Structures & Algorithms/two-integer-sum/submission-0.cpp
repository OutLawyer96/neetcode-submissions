class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapy;
        for(int i=0;i<nums.size();i++){
            mapy[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int diff=target-nums[i];
            if(mapy.count(diff) && mapy[diff]!=i){
                return {i,mapy[diff]};
            }
        }

        
    }
};
