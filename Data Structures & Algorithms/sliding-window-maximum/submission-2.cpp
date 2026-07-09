class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int maxi=nums[0];
        vector<int> res;
        for(int i=1;i<k;i++){
            maxi=max(maxi,nums[i]);
        }
        res.push_back(maxi);
        for(int i=k;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
            }
            else if(maxi==nums[i-k]){
                maxi=nums[i-k+1];
                for(int j=i-k+1;j<i+1;j++){
                    maxi=max(maxi,nums[j]);
                }
            }
            res.push_back(maxi);
        }
        return res;
    }
};
