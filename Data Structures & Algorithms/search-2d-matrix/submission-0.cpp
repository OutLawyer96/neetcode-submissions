class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int h=m*n-1,l=0;
        while(l<=h){
            int mid=(l+h)/2;
            int midi=mid/m;
            int midj=mid%m;
            if(matrix[midi][midj]<target){
                l=mid+1;
            }else if(matrix[midi][midj]>target){
                h=mid-1;
            }else{
                return true;
            }
        }
        return false;
    }
};
