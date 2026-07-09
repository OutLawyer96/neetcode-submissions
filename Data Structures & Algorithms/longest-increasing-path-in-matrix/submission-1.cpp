class Solution {
public:
    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    int finder(vector<vector<int>>& matrix,int i,int j,vector<vector<int>>& dp){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int curr=1;
        for(int k=0;k<4;k++){
            if(dx[k]+i>=0&& dx[k]+i<matrix.size()){
                if(dy[k]+j>=0 && dy[k]+j<matrix[0].size()){
                    if(matrix[i+dx[k]][j+dy[k]]>matrix[i][j]){
                        curr=max(curr,1+finder(matrix,i+dx[k],j+dy[k],dp));
                    }
                }
            }
        }
        dp[i][j]=curr;
        return curr;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int maxi=0;
        vector<vector<int>> dp(matrix.size(),vector<int> (matrix[0].size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                maxi=max(maxi,finder(matrix,i,j,dp));
            }
        }
        return maxi;
    }
};
