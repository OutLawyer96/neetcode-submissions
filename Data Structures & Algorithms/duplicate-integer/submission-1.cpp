class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> numse;
        for(int i=0;i<nums.size();i++){
            numse.insert(nums[i]);
        }
        if(numse.size()==nums.size()){
            return false;
        } else{
            return true;
        }
    }
};