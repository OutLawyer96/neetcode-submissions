class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        if(nums.empty()){
            return res;
        }
        vector<int> prefix;
        prefix.push_back(nums[0]);
        vector<int> suffix;
        suffix.push_back(nums[nums.size()-1]);
        for(int i=1;i<nums.size()-1;i++){
            prefix.push_back(prefix[i-1]*nums[i]);
        }
        for(int i=1;i<nums.size()-1;i++){
            suffix.push_back(suffix[i-1]*nums[nums.size()-1-i]);
        }
        res.push_back(suffix[suffix.size()-1]);
        for(int i=1;i<nums.size()-1;i++){
            res.push_back(prefix[i-1]*suffix[suffix.size()-i-1]);
        }
        res.push_back(prefix[prefix.size()-1]);
        return res;
    }
};
