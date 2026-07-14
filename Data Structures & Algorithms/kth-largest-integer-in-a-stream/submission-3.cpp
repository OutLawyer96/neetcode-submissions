class KthLargest {
public:
    int n;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        n=k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>n){
            pq.pop();
        }
        return pq.top();
    }
};
