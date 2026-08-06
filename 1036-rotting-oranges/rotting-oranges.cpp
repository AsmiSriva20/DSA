class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int rows= grid.size();
        int cols=grid[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        int minutes=-1;

        while(!q.empty()){
            int size=q.size();
            minutes++;
            while(size--){
                auto curr=q.front();
                q.pop();
                int row=curr.first;
                int col=curr.second;
                for(auto it: dir){
                    int nr=row+it.first;
                    int nc=col+it.second;

                    if( nr<rows && nc<cols && nr>=0 && nc>=0&&grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }

            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return (minutes==-1)? 0: minutes;
        
    }
};