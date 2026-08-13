class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        if(n==1) return 1;
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;

        vector<pair<int,int>> dir ={{1,0},{0,1},{1,1},{-1,-1},{-1,0},{0,-1},{-1,1},{1,-1}};
        int steps=1;

        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto curr = q.front();
                q.pop();
                int row= curr.first;
                int col=curr.second;
                for(auto it: dir){
                    int nr=row+it.first;
                    int nc=col+it.second;
                    if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0){
                        if(nr==n-1 && nc==n-1) return steps+1;
                       q.push({nr,nc});
                       grid[nr][nc]=1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};