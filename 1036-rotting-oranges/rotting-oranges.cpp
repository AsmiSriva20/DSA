class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2)
                q.push({i,j});
            }
        }
        vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        int minutes=-1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto curr=q.front();
                q.pop();
                for(auto it: dir){
                    int nr=it.first+curr.first;
                    int nc=it.second+curr.second;
                    if(nr>=0 && nc>=0 && nr<m && nc<n && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        q.push({nr,nc});
                    }
                }
            }
            minutes++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return (minutes==-1)?0:minutes;

    }
};