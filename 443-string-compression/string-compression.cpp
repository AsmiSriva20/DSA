class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0,index=0;
        while(i<n){
            char curr_char=chars[i];
            int count=0;
            while(i<n && curr_char==chars[i]){
                count++;i++;
            }
            chars[index]=curr_char;
            index++;

            string countstring=to_string(count);
            if(count>1){
            for(char &ch :countstring){
              chars[index]=ch;
              index++;
            }
        }
        }
      return index;  
    }
};