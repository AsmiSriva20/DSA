class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(); int m=p.size();
        vector<int> result;
        vector<int> pFreq(26,0), windowfreq(26,0);

        if(m>n) return result;
        for(char c:p){
            pFreq[c-'a']++;
        }
        for(int i=0;i<m;i++){
            windowfreq[s[i]-'a']++;
        }
        if(windowfreq==pFreq) result.push_back(0);

        for(int i=m;i<n;i++){
            windowfreq[s[i]-'a']++;
            windowfreq[s[i-m]-'a']--;
            if(windowfreq==pFreq){
                result.push_back(i-m+1);
            }

        }

     return result;
    
        
    }
};