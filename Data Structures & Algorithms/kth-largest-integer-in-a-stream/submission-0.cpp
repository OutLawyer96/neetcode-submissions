class KthLargest {
public:
    priority_queue<int> pq;
    int n;
    KthLargest(int k, vector<int>& nums) {
        n=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(val);
        priority_queue<int> temp=pq;
        for(int i=0;i<n-1;i++){
            temp.pop();
        }
        return temp.top();
    }
};
