class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p=0;
        int bp=-1,sp=-1;
        for(int i:prices){
            if(bp==-1){
                bp=i;
            }else if(i<bp){
                bp=i;
                sp=0;
            }else if(i>sp){
                sp=i;
            }
            if(sp>bp){
                if(sp-bp>p){
                    p=sp-bp;
                }
            }
        }
        return p;
    }
};
