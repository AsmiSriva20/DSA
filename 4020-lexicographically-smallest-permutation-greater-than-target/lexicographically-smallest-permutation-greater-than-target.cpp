class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        int f[26]={};
        for(char c:s) f[c-'a']++;
        string ans;

        function<bool(int,bool)> dfs = [&](int i,bool big) {
            if(i==t.size()) return big;
            int st=big?0:t[i]-'a';

            for(int c=st;c<26;c++) if(f[c]) {
                f[c]--; ans+=char(c+'a');
                if(dfs(i+1,big||c>t[i]-'a')) return true;
                f[c]++; ans.pop_back();
            }
            return false;
        };

        return dfs(0,false)?ans:"";
    }
};