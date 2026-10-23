class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> banword(banned.begin(),banned.end());
        unordered_map<string,int> words;
        int maxi=0;
        string word="",ans="";
        paragraph+= " ";
        for(char ch : paragraph){
            if(isalpha(ch)){
                word+=tolower(ch);
            }
            else{
                if(word!=""){
                if(banword.find(word)==banword.end() ){
                 words[word]++; 
                }
                if(words[word]>maxi) {ans=word; maxi=words[word];}
                
             
            } word="";
        }
        }
        return ans;
        
    }
};