class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldcolor, int newcolor){
        image[sr][sc]=newcolor;
        int rows= image.size();
        int cols =image[0].size();
        vector<pair<int,int>> dir= {{1,0},{0,1},{-1,0},{0,-1}};

        for(auto it: dir){
            int nr=sr+it.first;
            int nc=sc+it.second;
            if(nr>=0 && nr<rows && nc>=0 && nc < cols && image[nr][nc]==oldcolor){
                dfs(image,nr,nc,oldcolor,newcolor);
            }
        }
    }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor= image[sr][sc];
        if(oldcolor==color){
            return image;
        }
        dfs(image,sr,sc,oldcolor,color);
        return image;
        
    }
};