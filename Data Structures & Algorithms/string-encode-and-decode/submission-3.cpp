class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(string t:strs){
            s+=to_string(t.length());
            s+="#";
            s+=t;
        }
        cout<<s<<endl;
        return s;

    }

    vector<string> decode(string s) {
        vector<string> strs;
        for(int i=0;i<s.length();i++){
            if(s[i+1]!='#'){
                string k="";
                while(s[i]!='#'){
                    k+=s[i];
                    i++;
                }
                string t="";
                int n=stoi(k);
                for(int j=i+1;j<i+n+1;j++){
                    t+=s[j];
                }
                cout<<t<<endl;
                strs.push_back(t);
                i+=n;
            }
            else{
                string t="";
                int n=s[i]-'0';
                for(int j=i+2;j<i+n+2;j++){
                    t+=s[j];
                }
                cout<<t<<endl;
                strs.push_back(t);
                i+=n+1;
            }
        }    
        return strs;
    }
};
