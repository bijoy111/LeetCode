class Solution {
public:
    void move(vector<vector<int>>& grid,int i,int j)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) {
            return;
        }


        grid[i][j] = 0;

        if (i + 1 < rows && grid[i + 1][j] == 1) {
            move(grid, i + 1, j);
        }
        if (i - 1 >= 0 && grid[i - 1][j] == 1) {
            move(grid, i - 1, j);
        }
        if (j + 1 < cols && grid[i][j + 1] == 1) {
            move(grid, i, j + 1);
        }
        if (j - 1 >= 0 && grid[i][j - 1] == 1) {
            move(grid, i, j - 1);
        }

        /*
        grid[i][j]=0;
        if(grid[i+1][j]==1&&(i+1)<grid.size())
        {
            move(grid,i+1,j);
        }
        if(grid[i-1][j]==1&&(i-1)>=0)
        {
            move(grid,i-1,j);
        }
        if(grid[i][j+1]==1&&(j+1)<grid[0].size())
        {
            move(grid,i,j+1);
        }
        if(grid[i][j-1]==1&&(j-1)>=0)
        {
            move(grid,i,j-1);
        }
        */
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int r1=0;
        int rn=grid.size();
        int j1=0;
        int jn=grid[0].size();

        for(int j=0;j<jn;j++)
        {
            if(grid[r1][j]==1)
            {
                move(grid,r1,j);
            }
            if(grid[rn-1][j]==1)
            {
                move(grid,rn-1,j);
            }
        }   


        
        for(int i=0;i<grid.size();i++)
        {
            if(grid[i][j1]==1)
            {
                move(grid,i,j1);
            }
            if(grid[i][jn-1]==1)
            {
                move(grid,i,jn-1);
            }
        }

        long int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                    ans++;
            }
        }
        return ans;
    }
};