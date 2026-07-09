class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int f=0;
        unordered_map<char,int> map;
        int max=0;
        for(int i=0;i<s.length();i++){
            if(map.find(s[i])!=map.end() && map[s[i]]>=f){
                f=map[s[i]]+1;
                map[s[i]]=i;
            }else{
                map[s[i]]=i;
            }
            max=i-f+1>max?i-f+1:max;
        }
        return max;
    }
};
