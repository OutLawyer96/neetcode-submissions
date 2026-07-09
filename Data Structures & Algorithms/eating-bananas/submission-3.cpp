class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high=*max_element(piles.begin(),piles.end()),low=1;
        int mid=(low+high)/2;
        int min=0;
        while(low<=high){
            mid=low+(high-low)/2;
            long long sum=0;
            for(int i=0;i<piles.size();i++){
                sum+=ceil((double)piles[i]/mid);
            }
            if(sum>h){
                low=mid+1;
            }else{
                min=mid;
                high=mid-1;
            }
        }
        return min;
    }
};
