class Solution {
public:
    double part(vector<int>& small,vector<int>& large,int n,int m){
        int l=(n+m)/2;
        if((n+m)%2!=0){
            l++;
        }
        int low=0;
        int high=n;
        int mid=(high+low)/2;
        double ans=0;
        while(high>=low){
            mid=(high+low)/2;
            int left2,right2;
            int left1=left2=-1e9;
            int right1=right2=1e9;
            if(mid-1>=0 && mid-1<n){
                left1=small[mid-1];
            }
            if(l-mid-1>=0 && l-mid-1<m){
                left2=large[l-mid-1];
            }
            if(mid>=0 && mid<n){
                right1=small[mid];
            }
            if(l-mid>=0 && l-mid<m){
                right2=large[l-mid];
            }
            if(left1<=right2 && left2<=right1){
                if((n+m)%2==0){
                    ans=(max(left1,left2)+min(right1,right2))/2.0;
                }else{
                    ans=max(left1,left2);
                }
                break;
            }else if(left1>right2){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        if(n<m){
            return part(nums2,nums1,n,m);
        }else{
            return part(nums1,nums2,m,n);
        }
    }
};
