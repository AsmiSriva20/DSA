class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>words(wordList.begin(),wordList.end());
        if(words.find(endWord)==words.end()) return 0;
        queue<string>q;
        q.push(beginWord);
        words.erase(beginWord);
        int steps=1;
        
        while(!q.empty()){
            int n=q.size();
            while(n--){
                string s=q.front();
                q.pop();
                if(s==endWord) return steps;
                for(int i=0;i<s.size();i++){
                    char original=s[i];
                    for(char ch='a';ch<='z';ch++){
                        s[i]=ch;
                        if(words.find(s)!=words.end()){ q.push(s);
                        words.erase(s);}
                    }
                    s[i]=original;
                }
            }
            steps++;
        }
    

      return 0;
    }
};