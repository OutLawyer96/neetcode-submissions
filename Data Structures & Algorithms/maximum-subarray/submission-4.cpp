class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=0;
        int highest=nums[0];
        for(int i=0;i<nums.size();i++){
            if(ans<0){
                ans=0;
            }
            ans+=nums[i];
            highest=max(highest,ans);
        }
        return highest;
    }
};
