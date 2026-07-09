class Solution {
public:
    void backtrack(int pos,vector<int> used,vector<int>& nums , vector<int>& curr,vector<vector<int>>& res){
        if(pos>=nums.size()){
            res.push_back(curr);
            return;
        }
        bool flag=false;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<used.size();j++){
                if(used[j]==i){
                    flag=true;
                }
            }
            if(flag==true){
                flag=false;
                continue;
            }
            curr.push_back(nums[i]);
            used.push_back(i);
            backtrack(pos+1,used,nums,curr,res);
            curr.pop_back();
            used.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        vector<int> used;
        backtrack(0,used,nums,curr,res);
        return res;

    }
};
