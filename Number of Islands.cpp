class Solution {
public:
    long int ans=0;
    void move(vector<vector<char>>& grid,int i,int j)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) {
            return;
        }


        grid[i][j] = '0';

        if (i + 1 < rows && grid[i + 1][j] == '1') {
            move(grid, i + 1, j);
        }
        if (i - 1 >= 0 && grid[i - 1][j] == '1') {
            move(grid, i - 1, j);
        }
        if (j + 1 < cols && grid[i][j + 1] == '1') {
            move(grid, i, j + 1);
        }
        if (j - 1 >= 0 && grid[i][j - 1] == '1') {
            move(grid, i, j - 1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    move(grid,i,j);
                }
            }
        }
        return ans;
    }
};