class Solution {
public:
    void dfs(vector<int>& nums,int i,int target,vector<int>& subset,set<vector<int>>& res){
        if(target==0){
            res.insert(subset);
            return;
        }
        if(i>=nums.size()||target<0){
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums,i+1,target-nums[i],subset,res);
        subset.pop_back();
        int j=i+1;
        while(j<nums.size() && nums[j]==nums[i]){
            j++;
        }
        dfs(nums,j,target,subset,res);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,0,target,subset,res);
        vector<vector<int>> v(res.begin(),res.end());
        return v;
    }
};
