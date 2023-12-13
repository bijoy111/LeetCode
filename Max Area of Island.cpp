class Solution {
public:
    int n,m,tmp;
    void traverse(vector<vector<int>>& grid,int i,int j)
    {
        tmp++;
        grid[i][j]=0;
        if(i!=0&&grid[i-1][j]!=0)
        {
            traverse(grid,i-1,j);
        }
        if(i!=n-1&&grid[i+1][j]!=0)
        {
            traverse(grid,i+1,j);
        }
        if(j!=0&&grid[i][j-1]!=0)
        {
            traverse(grid,i,j-1);
        }
        if(j!=m-1&&grid[i][j+1]!=0)
        {
            traverse(grid,i,j+1);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        long int ans=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    continue;
                }
                tmp=0;
                traverse(grid,i,j);
                if(ans<tmp)
                {
                    ans=tmp;
                }
            }
        }
        return ans;
    }
};