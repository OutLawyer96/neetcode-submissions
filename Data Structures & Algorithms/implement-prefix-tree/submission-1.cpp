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
class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->children[word[i]-'a']){
                node->children[word[i]-'a']=new TrieNode();
            }
            node=node->children[word[i]-'a'];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        TrieNode* node=root;
        for(int i=0;i<word.length();i++){
            if(!node->children[word[i]-'a']){
                return false;
            }
            node=node->children[word[i]-'a'];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->children[prefix[i]-'a']){
                return false;
            }
            node=node->children[prefix[i]-'a'];
        }
        return true;
    }
};
