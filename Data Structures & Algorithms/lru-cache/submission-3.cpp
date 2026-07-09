class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
    Node* head=new Node(1,0);
    Node* mru=new Node(1,0);
    unordered_map<int,Node*> pages;
    int count=0;
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    
    int get(int key) {
        if(pages.count(key)){
            if(mru!=pages[key]){
                mru->next=pages[key];
                if(pages[key]->prev){
                    pages[key]->prev->next=pages[key]->next;
                }else{
                    head=pages[key]->next;
                }
                pages[key]->next->prev=pages[key]->prev;
                pages[key]->prev=mru;
                mru=pages[key];
                mru->next=nullptr;
            }
            return pages[key]->val;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(count>0 && pages.count(key)){
            pages[key]->val=value;
            if(mru!=pages[key]){
                mru->next=pages[key];
                if(pages[key]->prev){
                    pages[key]->prev->next=pages[key]->next;
                }else{
                    head=pages[key]->next;
                }
                pages[key]->next->prev=pages[key]->prev;
                pages[key]->prev=mru;
                mru=pages[key];
                mru->next=nullptr;
            }
        }
        else if(count==0){
            head->prev=nullptr;
            head->key=key;
            head->val=value;
            pages[key]=head;
            mru=head;
            count++;
        }
        else if(count<capacity){
            count++;
            Node* curr=new Node(key,value);
            mru->next=curr;
            curr->prev=mru;
            mru=curr;
            pages[key]=curr;
        }else if(capacity>1){
            Node* temp=head->next;
            pages.erase(head->key);
            head=temp;
            head->prev=nullptr;
            Node* curr=new Node(key,value);
            mru->next=curr;
            curr->prev=mru;
            mru=curr;
            pages[key]=curr;
        }else{
            pages.erase(head->key);
            Node* curr=new Node(key,value);
            pages[key]=curr;
            mru=curr;
            head=curr;
        }
    }
};
