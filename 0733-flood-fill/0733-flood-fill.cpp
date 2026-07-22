class Solution {
private:
        
        void dfs(vector<vector<int>>& image ,int sr, int sc,int color,int originalColor)
        {        
            if(sr <0 || sr>=image.size() || sc < 0 || sc>=image[0].size() || image[sr][sc] != originalColor ) 
            {
                return ;
            }
            image[sr][sc]=color;

            dfs(image, sr + 1, sc, color, originalColor); // Down
            dfs(image, sr - 1, sc, color, originalColor); // Up
            dfs(image, sr, sc - 1, color, originalColor); // Left
            dfs(image, sr, sc + 1, color, originalColor);
        }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int originalColor = image[sr][sc];
        if(originalColor==color)
        {
            return image;
        }

        dfs(image, sr, sc, color, originalColor);
        return image;
    }
};