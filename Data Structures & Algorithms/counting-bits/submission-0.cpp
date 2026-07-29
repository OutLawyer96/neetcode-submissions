class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            int j=i;
            int ans=0;
            while(j!=0){
                j&=j-1;
                ans++;
            }
            res.push_back(ans);
        }
        return res;
    }
};
