class Solution {
public:
    vector<pair<int,int>> directions= {{-1,0},{1,0},{0,-1},{0,1}};
     
    bool dfs(vector<vector<char>>& board, string &word,int i,int j,int idx){
        if(idx==word.size()){
            return true;
        }
        if(i<0||j<0||i>=board.size()||j>=board[0].size()||board[i][j]!=word[idx]){
            return false;
        }
        char temp= board[i][j];
        board[i][j] = '%';
        for(auto [x,y]: directions){
            if(dfs(board,word,i+x,j+y,idx+1)) return true;
        }
        board[i][j]=temp;
        return false;

        
    }


    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (dfs(board,word,i,j,0)) return true;
            } 
        }
        return false;
    }
};