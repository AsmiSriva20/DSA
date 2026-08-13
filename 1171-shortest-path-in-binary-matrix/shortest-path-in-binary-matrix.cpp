class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1  || grid[n-1][n-1]==1) return -1;
        using P= pair<int, pair<int,int>>;
        priority_queue<P, vector<P>, greater<P>>pq;
        vector<vector<int>>distance(n,vector<int>(n,INT_MAX));

        vector<pair<int,int>> dir = {{1,0}, {0,1}, {1,1}, {-1,-1},{-1,0}, {0,-1}, {-1,1}, {1,-1}};
        pq.push({1, {0,0}});
        distance[0][0] = 1;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int dist=curr.first;
            int row=curr.second.first;
            int col=curr.second.second;
            if(row==n-1 && col==n-1) return dist;
            for(auto it: dir){
                int nr= row+it.first;
                int nc=col+it.second;
                if(nr>=0 && nc>=0 && nr<n && nc<n && grid[nr][nc]==0){
                    int nayadist=1+dist;
                    if(nayadist<distance[nr][nc]){
                        distance[nr][nc]=nayadist;
                        pq.push({nayadist,{nr,nc}});
                    }
                }
            }


        }

   return -1;
        
    }
};
