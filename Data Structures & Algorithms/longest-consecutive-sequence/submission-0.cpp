class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        int max=0;
        for(int i:nums){
            if(!s.count(i-1)){
                int cur=i;
                int len=1;
                while(s.count(cur+1)){
                    cur++;
                    len++;
                }
                if(len>max){
                    max=len;
                }
            }
        }
        return max;
    }
};
