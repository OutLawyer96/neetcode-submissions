class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stacky;
        vector<int> pre(heights.size(),heights.size());
        stacky.push(0);
        for(int i=1;i<heights.size();i++){
            while(!stacky.empty() && heights[stacky.top()]>heights[i]){
                pre[stacky.top()]=i-stacky.top();
                stacky.pop();
            }
            stacky.push(i);
        }
        stack<int> stacker;
        vector<int> post(heights.size(),heights.size());
        reverse(heights.begin(),heights.end());
        stacker.push(0);
        for(int i=1;i<heights.size();i++){
            while(!stacker.empty() && heights[stacker.top()]>heights[i]){
                post[stacker.top()]=i-stacker.top();
                stacker.pop();
            }
            stacker.push(i);
        }
        reverse(heights.begin(),heights.end());
        for(int i=0;i<heights.size();i++){
            if(pre[i]==heights.size()){
                pre[i]=heights.size()-i;
            }
            if(post[i]==heights.size()){
                post[i]=heights.size()-i;
            }
        }
        reverse(post.begin(),post.end());
        for(int i=0;i<heights.size();i++){
            cout<<pre[i]<<" "<<post[i]<<" "<<endl;
        }
        
        
        int max=0;
        for(int i=0;i<heights.size();i++){
            int curr=heights[i]*(pre[i]+post[i]-1);
            if(max<curr){
                max=curr;
            }
        }
        return max;
    }
};
