class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        vector<int> res;
        stack<int> ans;
        for(int i=digits.size()-1;i>=0;i--){
            int curr=digits[i]+carry;
            carry=curr/10;
            ans.push(curr%10);
        }
        if(carry>0){
            ans.push(carry);
        }
        while(!ans.empty()){
            res.push_back(ans.top());
            ans.pop();
        }
        return res;
    }
};
