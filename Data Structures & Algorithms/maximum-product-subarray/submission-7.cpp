class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prevmax=nums[0];
        int prevmin=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==0){
                prevmax=0;
                prevmin=0;
            }else if(nums[i]>0){
                prevmax=max(nums[i],prevmax*nums[i]);
                prevmin=min(nums[i],prevmin*nums[i]);
            }else{
                int temp=prevmax;
                prevmax=max(nums[i],prevmin*nums[i]);
                prevmin=min({nums[i],temp*nums[i],prevmin*nums[i]});
            }
            ans=max(prevmax,ans);
        }
        return ans;
    }
};
