class Solution {
public:
    bool dfs(vector<vector<char>>& board, string &word,int i,int j, int index){
         int m=board.size();
         int n=board[0].size();
         if(index==word.size()) return true;
         if(i<0 || j<0 || i>=m || j>=n|| board[i][j]!=word[index]||board[i][j]=='$') return false;
         char temp=board[i][j];
         vector<pair<int,int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
         board[i][j]='$';
         for(auto it:dir){
            int nr= i+it.first;
            int nc= j+it.second;
            if(dfs(board,word,nr,nc,index+1)) return true;
         }
         board[i][j]=temp;
         return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,word,i,j,0)) return true;
            }
        }
      return false;  
    }
};