class LRUCache {
private:
    struct Node{
        int key; int value;
        Node* prev; Node* next;
        Node(int k,int v){
            key=k; value=v;
            prev=NULL; next=NULL;
        }
    };
     int cap; unordered_map<int,Node*>mp;
     Node* head; Node* tail;

     void addNode(Node* node){
        Node* start= head->next;
        node->prev=head;
        node->next=start;
        head->next=node;
        start->prev=node;
        return;
     }
     void delNode(Node* node){
        Node* previous=node->prev;
        Node* follower=node->next;
        previous->next=follower;
        follower->prev=previous;
        return;
     }

public:
    
    LRUCache(int capacity) {
        cap=capacity; 
        head= new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;    

    }
   
    int get(int key) {
        auto it=mp.find(key);
        if(it==mp.end()){return -1;}
        delNode(it->second);
        addNode(it->second);
        return it->second->value;
    }
    
    void put(int key, int value) {
        auto it=mp.find(key);
        if(it!=mp.end()){
            it->second->value=value;
            delNode(it->second);
            addNode(it->second);
            return;
        }
        if(cap==0){
            mp.erase(tail->prev->key);
            delNode(tail->prev); 
            Node* putit=new Node(key,value);
            addNode(putit);
            mp[key]=putit;
        }
        else{
            cap--;
            Node* putit=new Node(key,value);
            addNode(putit);
            mp[key]=putit;
        }
        
    

        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */