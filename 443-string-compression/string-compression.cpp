class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        char curr_char;
        int i=0,idx=0;
        while(i<n){
            curr_char=chars[i];
            int count=0;
            while(i<n && curr_char==chars[i]){
                count++;
                i++;
            }
            chars[idx]=curr_char;
            idx++;
            if(count>1){
                string countkastring = to_string(count);
                for(char &ch: countkastring){
                    chars[idx]=ch;
                    idx++;
                }
            }
            }
            return idx;
        }

      
    
};