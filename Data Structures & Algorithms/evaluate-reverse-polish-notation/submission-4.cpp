class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> t;
        for(string s: tokens){
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                int a=t.top();
                t.pop();
                int b=t.top();
                t.pop();
                if(s=="+"){
                    t.push(a+b);
                }else if(s=="*"){
                    t.push(a*b);
                }else if(s=="-"){
                    t.push(b-a);
                }else if(s=="/"){
                    t.push((int)(b/a));
                }
            }
            else{
                t.push(stoi(s));
            }
        }
        return t.top();
    }
};
