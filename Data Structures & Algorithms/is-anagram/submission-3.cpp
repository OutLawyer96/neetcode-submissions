class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char , int> map1;
        unordered_map<char , int> map2;
        for(char i: s){
            if(map1[i]){
                map1[i]++;
            }
            else{
                map1[i]=1;
            }
        }
        for(char i: t){
            if(map2[i]){
                map2[i]++;
            }
            else{
                map2[i]=1;
            }
        }
        if(map1.size()!=map2.size()){
            return false;
        }
        for(const auto& [i,j]: map1){
            if(map1[i]!=map2[i])
            return false;
        }
        return true;
    }
};
