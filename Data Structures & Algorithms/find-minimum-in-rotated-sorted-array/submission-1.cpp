class Solution {
public:
    int findMin(vector<int> &nums) {
        int high=nums.size()-1,low=0;
        
        int mid=(low+high)/2;
        while(low<=high){
            mid=(low+high)/2;
            if(mid!=nums.size()-1){
                if(nums[mid]>nums[mid+1]){
                    return nums[mid+1];
                }
                else if(nums[mid]>nums[nums.size()-1]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }else{
                if(nums[mid]>nums[0]){
                    return nums[0];
                }
                else if(nums[mid]>nums[nums.size()-1]){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
        }
        return nums[mid];
    }
};
