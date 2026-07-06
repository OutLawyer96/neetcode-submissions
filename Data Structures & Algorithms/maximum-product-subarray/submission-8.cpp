class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prevmax=nums[0];
        int prevmin=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int temp=prevmax;
            prevmax=max({nums[i],prevmax*nums[i],prevmin*nums[i]});
            prevmin=min({nums[i],temp*nums[i],prevmin*nums[i]});
            ans=max(prevmax,ans);
        }
        return ans;
    }
};
