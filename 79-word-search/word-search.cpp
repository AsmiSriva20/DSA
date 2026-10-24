class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int i, int j,int idx){
    int row=board.size();
        int col=board[0].size();
        if(idx==word.size()) return true;
        if(i<0 || j<0 || i>=row || j>=col || board[i][j]!=word[idx] || board[i][j]=='$'){
          return false; }
          char temp=board[i][j];
          board[i][j]='$';
          vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
          for(auto it:dir){
            int nr= it.first+i;
            int nc=it.second+j;
           
                if(dfs(board,word,nr,nc,idx+1)){
                    board[i][j]=temp;
                    return true;
                }       
            
          }
        board[i][j]=temp;
        return false;
        }   
        
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
       
      return false;  
    }
};