class Solution {
public:
    void dfs(vector<vector<int>>& image, int row, int col, int newcolor, int oldcolor){
        image[row][col]=newcolor;
        int m=image.size();
        int n=image[0].size();
        vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        for(auto it : dir){
             int nr=row+it.first;
             int nc=col+it.second;
             if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc]==oldcolor){
                dfs(image,nr,nc,newcolor,oldcolor);
             }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int oldcolor=image[sr][sc];
        if(oldcolor==color) return image;
        dfs(image,sr,sc,color,oldcolor);
        return image;
        
    }
};