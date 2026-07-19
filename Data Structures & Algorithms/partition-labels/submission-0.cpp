class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> freq(26,0);
        for(int i=s.length()-1;i>=0;i--){
            if(freq[s[i]-'a']==0){
                freq[s[i]-'a']=i;
            }
        }
        int last=0;
        int size=0;
        vector<int> res;
        for(int i=0;i<s.length();i++){
            size++;
            if(last<freq[s[i]-'a']){
                last=freq[s[i]-'a'];
            }
            if(last==i){
                res.push_back(size);
                size=0;
                last=0;
            }
        }
        return res;
    }
};
