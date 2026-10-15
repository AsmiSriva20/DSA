class Solution {
public: 
    void dfs(vector<vector<char>>&grid,int i,int j){
        int r=grid.size();
        int c=grid[0].size();
        if(i>=r || i<0 || j>=c || j<0 || grid[i][j]=='0') return;
        
        grid[i][j]='0';
        dfs(grid,i+1,j);
        dfs(grid,i,j+1);
        dfs(grid,i-1,j);
        dfs(grid,i,j-1);
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);

                }
                
              
            }
        }
        return count;

        
    }
};