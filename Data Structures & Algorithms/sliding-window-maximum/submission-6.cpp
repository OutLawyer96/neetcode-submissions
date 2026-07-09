class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> maxer;
        vector<int> res;
        for(int i=0;i<k;i++){
            maxer.insert(nums[i]);
        }
        res.push_back(*maxer.rbegin());
        for(int i=k;i<nums.size();i++){
            maxer.erase(maxer.find(nums[i-k]));
            maxer.insert(nums[i]);
            res.push_back(*maxer.rbegin());
        }
        return res;
    }
};
