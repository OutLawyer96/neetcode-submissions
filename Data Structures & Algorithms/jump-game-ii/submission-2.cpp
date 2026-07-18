class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int count=0;
        queue<int> q;
        q.push(0);
        vector<bool> visited(nums.size(),false);
        visited[0]=true;
        while(!q.empty()){
            count++;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int curr=q.front();
                q.pop();
                for(int j=1;j<nums[curr]+1;j++){
                    if(curr+j>=nums.size()-1){
                        return count;
                    }
                    if(visited[curr+j]){
                        continue;
                    }
                    q.push(curr+j);
                    visited[curr+j]=true;
                }
            }
        }
        return count;
    }
};
