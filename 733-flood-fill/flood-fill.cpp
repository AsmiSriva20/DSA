class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int color,int oldcolor){
        int r=image.size();
        int c=image[0].size();
        if(i<0 || j<0 || i>=r || j>=c || image[i][j]!=oldcolor) return;
        image[i][j]=color;
        dfs(image,i+1,j,color,oldcolor);
        dfs(image,i,j+1,color,oldcolor);
        dfs(image,i-1,j,color,oldcolor);
        dfs(image,i,j-1,color,oldcolor);
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       int oldcolor=image[sr][sc];
       if(oldcolor==color) return image;
       dfs(image,sr,sc,color,oldcolor);
       return image;
    }
};