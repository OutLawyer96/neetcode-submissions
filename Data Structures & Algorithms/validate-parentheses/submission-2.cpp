class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(char c:s){
            if(c=='('||c=='{'||c=='['){
                t.push(c);
            }else{
                if(t.empty()){
                    return false;
                }
                char d=t.top();
                if((d=='('&&c==')')||(d=='{'&&c=='}')||(d=='['&&c==']')){
                    t.pop();
                }
                else{
                    return false;
                }
            }
        }
        return t.empty();
    }
};
