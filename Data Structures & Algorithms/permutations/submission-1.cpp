class Solution {
public:
    void backtrack(int pos,vector<bool> used,vector<int>& nums , vector<int>& curr,vector<vector<int>>& res){
        if(pos>=nums.size()){
            res.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            curr.push_back(nums[i]);
            used[i]=true;;
            backtrack(pos+1,used,nums,curr,res);
            curr.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<bool> used(nums.size(),false);
        backtrack(0,used,nums,curr,res);
        return res;

    }
};
