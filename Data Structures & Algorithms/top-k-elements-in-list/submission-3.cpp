class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        vector<vector<int>> order(nums.size()+1);
        for(int i:nums){
            freq[i]++;
        }
        for(const auto& pair:freq){
            order[pair.second].push_back(pair.first);
        }
        vector<int> res;
        for(int i=nums.size();i>=0;i--){
            if(order[i].empty()){
                continue;
            }
            else{
                res.insert(res.end(),order[i].begin(),order[i].end());
                k-=order[i].size();
            }
            if(k<0){
                while(k!=0){
                    res.pop_back();
                    k++;
                }
            }
            if(k==0){
                return res;
            }
        }
    }
};
