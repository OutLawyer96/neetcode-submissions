class Solution {
public:
    bool checkValidString(string s) {
        stack<int> stars;
        stack<int> open;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                stars.push(i);
            }else if(s[i]=='('){
                open.push(i);
            }else{
                if(!open.empty()){
                    open.pop();
                }else if(!stars.empty()){
                    stars.pop();
                }else{
                    return false;
                }
            }
        }
        while(!open.empty()){
            if(!stars.empty() && stars.top()>open.top()){
                open.pop();
                stars.pop();
            }else{
                return false;
            }
        }
        return true;
    }
};
