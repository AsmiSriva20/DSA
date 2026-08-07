class Solution {
public:
    void dfs(vector<vector<char>>& grid,int row, int col){
        grid[row][col]='0';
        int rows=grid.size();
        int cols=grid[0].size();
        vector<pair<int,int>> dir ={{1,0},{-1,0},{0,1},{0,-1}};
        for(auto it: dir){
            int nr=row+it.first;
            int nc=col+it.second;
            if(nr>=0 && nr<rows && nc>=0 && nc<cols && grid[nr][nc]=='1'){
                dfs(grid,nr,nc);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();

        int islands=0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]=='1'){
                    islands++;
                    dfs(grid,i,j);
                }
            }
        }
        return islands;

        
    }
};