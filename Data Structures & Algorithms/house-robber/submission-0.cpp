class Solution {
public:
    int rob(vector<int>& nums) {
        int p1=0;
        int p2=0;
        int total=0;
        for(int i=0;i<nums.size();i++){
            int curr=nums[i];
            if(curr+p1>p2){
                total=curr+p1;
            }else{
                total=p2;
            }
            p1=p2;
            p2=total;
        }
        return total;
    }
};