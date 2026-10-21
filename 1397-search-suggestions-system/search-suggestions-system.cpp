class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        vector<vector<string>> ans;
        string prefix="";
        for(char c: searchWord){
            vector<string>suggestions;
            prefix+=c;
            auto it= lower_bound(products.begin(),products.end(),prefix);
            for(int i=it-products.begin();i<products.size() && suggestions.size()<3;i++){
               if(products[i].substr(0,prefix.size())!=prefix) break;
               suggestions.push_back(products[i]);
            }
            ans.push_back(suggestions);
        }
      return ans;
        
    }
};