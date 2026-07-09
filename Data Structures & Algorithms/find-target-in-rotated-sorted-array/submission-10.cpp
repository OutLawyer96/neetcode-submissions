class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high=nums.size()-1;
        int low=0;
        int mid=(low+high)/2;
        while(low<=high){
            mid=(low+high)/2;
            cout<<nums[mid]<<endl;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>nums[nums.size()-1]){
                if(nums[mid]>target && target>=nums[low]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }else{
                if(nums[mid]<target && target<=nums[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return -1;
    }
};
