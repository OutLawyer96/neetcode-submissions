class Solution {
public:
    int finder(vector<int>& nums, int target,int i){
        if(i==nums.size()){
            if(target==0){
                return 1;
            }else{
                return 0;
            }
        }
        int ways=0;
        ways+=finder(nums,target-nums[i],i+1);
        ways+=finder(nums,target+nums[i],i+1);
        return ways;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return finder(nums,target,0);
    }
};
