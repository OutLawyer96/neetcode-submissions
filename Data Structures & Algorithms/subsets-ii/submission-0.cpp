class Solution {
public:
    void dfs(int i,vector<int>& nums,vector<int>& subset,vector<vector<int>>& res ){
        if(i==nums.size()){
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(i+1,nums,subset,res);
        subset.pop_back();
        int j=i+1;
        while(j<nums.size() && nums[j]==nums[i]){
            j++;
        }
        dfs(j,nums,subset,res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(),nums.end());
        dfs(0,nums,subset,res);
        return res;
    }
};
