class Solution {
public:
    void dfs(int target ,int i,vector<int>& nums,vector<int>& subset, vector<vector<int>>& res){
        if(i==nums.size()||target<0){
            return;
        }else if(target==0){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(target-nums[i],i,nums,subset,res);
        subset.pop_back();
        dfs(target,i+1,nums,subset,res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(target,0,nums,subset,res);
        return res;
    }
};
