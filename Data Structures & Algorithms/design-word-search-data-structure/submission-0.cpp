class TrieNode{
public:
    bool isEnd;
    TrieNode* children[26];
    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
    }

};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node=root;
        for(char c:word){
            int idx=c-'a';
            if(!node->children[idx]){
                node->children[idx]=new TrieNode();
            }
            node=node->children[idx];
        }
        node->isEnd=true;
    }

    bool check(TrieNode* node,string word,int k){
        if(k==word.size()){
            return node->isEnd;
        }

        if(word[k]=='.'){
            for(int i=0;i<26;i++){
                if(node->children[i]){
                    if(check(node->children[i],word,k+1)){
                        return true;
                    }
                }
            }
            return false;
        }else{
            if(!node->children[word[k]-'a']){
                return false;
            }
            return check(node->children[word[k]-'a'],word,k+1);
        }
    }

    bool search(string word) {
        return check(root,word,0);
    }
};
