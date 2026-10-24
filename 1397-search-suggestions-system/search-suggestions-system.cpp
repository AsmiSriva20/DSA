class Solution {
private:
  struct node{
    vector<string>ans;
    node* child[26]={};
  };

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        node* root= new node();
        for(string s: products){
            node* rooot=root;
            for(char c:s){
                int idx= c-'a';
                if(rooot->child[idx]==NULL) rooot->child[idx]=new node();
                rooot=rooot->child[idx];
                if(rooot->ans.size()<3) rooot->ans.push_back(s);
            }

        
        }
        node* thisnode=root;
        vector<vector<string>> suggest;
        for(char ch:searchWord){
            int idx=ch-'a';
                if(thisnode != NULL && thisnode->child[idx] != NULL) {
        thisnode = thisnode->child[idx];
        suggest.push_back(thisnode->ans);
    }
    else {
        thisnode = NULL;
        suggest.push_back({});
    }
        }
        
    return suggest;}
};