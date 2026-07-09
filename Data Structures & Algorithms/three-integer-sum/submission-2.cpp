class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int diff=0-nums[i];
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]>diff){
                    r--;
                }else if(nums[l]+nums[r]<diff){
                    l++;
                }else{
                    res.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]){
                        l++;
                    }
                }
            }
        }
        return res;
    }
};
