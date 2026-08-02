class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        while(n!=1){
            int temp=0;
            while(n>0){
                temp+=(n%10)*(n%10);
                n/=10;
            }
            n =temp;
            if(mp.count(n)){
                return false;
            }
            mp[n]=1;
        }
        return true;
    }
};
