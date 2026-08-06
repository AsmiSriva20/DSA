class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue <pair <int, int>> q;

        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }
            }
        }

        int ans = -1;

        while(!q.empty()){
            int sz = q.size();
            ans++;

            for(int i = 0; i<sz; i++){
                auto f = q.front();
                q.pop();
                
                int row = f.first;
                int col = f.second;

                if(row - 1 >= 0) {
                    if(grid[row-1][col] == 1){
                        grid[row-1][col] = 2;
                        q.push({row-1 , col});
                    }
                }

                if(row + 1 < m){
                    if(grid[row + 1][col] == 1){
                        grid[row+1][col] = 2;
                        q.push({row+1 , col});
                    }
                }


                if(col - 1 >= 0){
                    if(grid[row][col - 1] == 1){
                        grid[row][col-1] = 2;
                        q.push({row , col-1});
                    }
                }


                if(col + 1 < n){
                    if(grid[row][col + 1] == 1){
                        grid[row][col+1] = 2;
                        q.push({row , col+1});
                    }
                }
            }

            
        }

        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        if(ans == -1){
            return 0;
        }

        return ans;
    }
};