class TrieNode{
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }
};
class Solution {
public:
    void insert(TrieNode* node,string word){
        for(char c:word){
            int idx=c-'a';
            if(!node->children[idx]){
                node->children[idx]=new TrieNode();
            }
            node=node->children[idx];
        }
        node->isEnd=true;
    }

    vector<int> dx={-1,1,0,0};
    vector<int> dy={0,0,-1,1};

    void find(TrieNode* node,vector<vector<char>>& board,vector<vector<int>>& visited,int i, int j, vector<string>& res,string& curr){
        if(node->isEnd){
            res.push_back(curr);
            node->isEnd=false;
        }
        for(int k=0;k<4;k++){
            int ci=i+dx[k];
            int cj=j+dy[k];
            if(ci>=0 && ci<board.size() && cj>=0 && cj<board[0].size() && !visited[ci][cj] ){
                int idx=board[ci][cj]-'a';
                if(node->children[idx]){
                    visited[ci][cj]=1;
                    curr+=board[ci][cj];
                    find(node->children[idx],board,visited,ci,cj,res,curr);
                    curr.pop_back();
                    visited[ci][cj]=0;
                }
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root=new TrieNode();
        for(int i=0;i<words.size();i++){
            insert(root,words[i]);
        }

        vector<string> res;
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(root->children[board[i][j]-'a']){
                    visited[i][j]=1;
                    string temp="";
                    temp+=board[i][j];
                    find(root->children[board[i][j]-'a'], board,visited,i,j,res,temp);
                    visited[i][j]=0;
                }
            }
        }
        return res;
    }
};
