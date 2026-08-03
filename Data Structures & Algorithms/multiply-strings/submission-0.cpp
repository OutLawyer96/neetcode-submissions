class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1[0]=='0' || num2[0]=='0'){
            return "0";
        }
        vector<int> res(num1.size()+num2.size(),0);
        for(int i=num1.size()-1;i>=0;i--){
            int a=num1[i]-'0';
            for(int j=num2.size()-1;j>=0;j--){
                int b=num2[j]-'0';
                int pos=i+j+1;
                int sum = res[pos] + a * b;
                res[pos] = sum % 10;
                res[pos-1] += sum / 10;
            }
        }
        string ans="";
        bool flag=false;
        for(int i=0;i<res.size();i++){
            if(!flag && res[i]==0){
                continue;
            }
            flag=true;
            ans+=('0'+res[i]);
        }
        return ans;
    }
};
