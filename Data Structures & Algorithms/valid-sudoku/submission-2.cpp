class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> box1(9,false);
        vector<bool> box2(9,false);
        vector<bool> box3(9,false);
        for(int i=0;i<9;i++){
            vector<bool> countr(9,false);
            vector<bool> countc(9,false);
            if(i%3==0){
                box1.assign(9,false);
                box2.assign(9,false);
                box3.assign(9,false);
            }
            for(int j=0;j<9;j++){
                if(isdigit(board[i][j])){
                    if(j/3==0){
                        if(box1[board[i][j]-'1']==false){
                            box1[board[i][j]-'1']=true;
                        }
                        else{
                            return false;
                        }
                    }else if(j/3==1){
                        if(box2[board[i][j]-'1']==false){
                            box2[board[i][j]-'1']=true;
                        }
                        else{
                            return false;
                        }
                    }else{
                        if(box3[board[i][j]-'1']==false){
                            box3[board[i][j]-'1']=true;
                        }
                        else{
                            return false;
                        }
                    }
                    if(countr[board[i][j]-'1']==false){
                        countr[board[i][j]-'1']=true;
                    }
                    else{
                        return false;
                    }
                }
                if(isdigit(board[j][i])){
                    if(countc[board[j][i]-'1']==false){
                        countc[board[j][i]-'1']=true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
