/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        Node* root=new Node(node->val);
        queue<Node*> q1;
        queue<Node*> q2;
        unordered_map<Node*,Node*> mp;
        mp[node]=root;
        q1.push(node);
        q2.push(root);
        while(!q1.empty()){
            int sz=q1.size();
            for(int i=0;i<sz;i++){
                Node* curro=q1.front();
                Node* currn=q2.front();
                q1.pop();
                q2.pop();
                for(auto neighbour :curro->neighbors){
                    if(!mp.count(neighbour)){
                        Node* clone = new Node(neighbour->val);
                        currn->neighbors.push_back(clone);
                        mp[neighbour] = clone;
                        q1.push(neighbour);
                        q2.push(clone);
                    }else{
                        currn->neighbors.push_back(mp[neighbour]);
                    }
                }
            }
        }
        return root;
    }
};
