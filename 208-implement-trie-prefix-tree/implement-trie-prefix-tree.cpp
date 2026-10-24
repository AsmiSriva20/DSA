
class Trie {
private:
struct node{
   node* child[26];
   bool isEnd;
   node(){
    isEnd=false;
    for(int i=0;i<26;i++){
        child[i]=NULL;
    }
   }
   
};

public:
node* root;
    Trie() {
        root= new node();
    }
    
    void insert(string word) {
        node* var=root;
        for(char c: word){
            int idx= c-'a';
            if(var->child[idx]==NULL){
                var->child[idx]=new node();
            }
            var=var->child[idx];
        }
       var->isEnd=true;
        
    }
    
    bool search(string word) {
        node* some=root;
        for(char ch:word){
            int idx=ch-'a';
            if(some-> child[idx]==NULL) return false;
            some=some->child[idx];
        }
        return some->isEnd;
    }
    
    bool startsWith(string prefix) {
        node* nodee=root;
        for(char ch : prefix){
            int idx=ch-'a';
            if(nodee->child[idx]==NULL) return false;
            nodee=nodee->child[idx];
            
        }return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */