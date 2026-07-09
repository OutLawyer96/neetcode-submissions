class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,f=0;
        int maxi=0,maxf=0;
        unordered_map<char,int> map;
        while(f<s.length()){
            map[s[f]]++;
            maxf=max(maxf,map[s[f]]);
            while (f-l+1-maxf>k){
                map[s[l]]--;
                l++;
            }
            maxi=max(maxi,f-l+1);
            f++;
        }
        return maxi;
    }
};
