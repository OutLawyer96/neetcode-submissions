class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> freq;
        unordered_map<char,int> perm;
        for(int i=0;i<s1.length();i++){
            if(freq[s1[i]]){
                freq[s1[i]]++;
            }
            else{
                freq[s1[i]]=1;
            }
            if(perm[s2[i]]){
                perm[s2[i]]++;
            }
            else{
                perm[s2[i]]=1;
            }
        }
        if(freq==perm){
            return true;
        }
        for(int i=s1.length();i<s2.length();i++){
            if(perm[s2[i-s1.length()]]>1){
                perm[s2[i-s1.length()]]--;
            }else{
                perm.erase(s2[i-s1.length()]);
            }
            if(perm[s2[i]]){
                perm[s2[i]]++;
            }
            else{
                perm[s2[i]]=1;
            }
            if(freq==perm){
                return true;
            }
        }
        return false;
    }
};
