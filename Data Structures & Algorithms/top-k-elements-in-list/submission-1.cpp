class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<vector<int>> order(nums.size()+1);
        for(int i=nums.size();i>=0;i--){
            order[i]={};
        }
        for(int i:nums){
            freq[i]++;
        }
        for(const auto& pair:freq){
            order[pair.second].push_back(pair.first);
        }
        int count=0;
        vector<int> res;
        for(int i=nums.size();i>=0;i--){
            if(order[i].empty()){
                continue;
            }
            else{
                res.insert(res.end(),order[i].begin(),order[i].end());
                count+=order[i].size();
            }
            if(count==k){
                return res;
            }
        }
    }
};
