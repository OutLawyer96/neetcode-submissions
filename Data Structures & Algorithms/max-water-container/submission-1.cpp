class Solution {
public:
    int maxArea(vector<int>& heights) {
        int r=heights.size()-1;
        int max=min(heights[0],heights[r])*r;
        int l=0;
        while(l<r){
            int cur=min(heights[l],heights[r])*(r-l);
            if(cur>max){
                max=cur;
            }
            if(heights[l]<heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return max;
    }
};
