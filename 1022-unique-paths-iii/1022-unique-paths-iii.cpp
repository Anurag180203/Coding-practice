class Solution {
public:
    int f(int sx,int sy,int ex,int ey,int c,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(sx<0 || sy<0 ||sx>=grid.size() || sy>=grid[0].size() || grid[sx][sy]==-1)
            return 0;
        if(sx==ex && sy==ey)
        {
            if(c==0)
                return 1;
            else
                return 0;
        }
        vector<int>dirx = {-1,0,1,0},diry = {0,1,0,-1};
        int ans=0;
        for(int i=0;i<4;i++)
        {
            grid[sx][sy]=-1;
            c--;
            ans+=f(sx+dirx[i],sy+diry[i],ex,ey,c,grid,dp);
            grid[sx][sy]=0;
            c++;
        }
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans=0;
        int c=0;
        int n = grid.size(),m = grid[0].size();
        int sx,sy,ex,ey;
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<m;y++)
            {
                if(grid[x][y]==-1)
                continue;
                if(grid[x][y]==1)
                {
                    sx=x;
                    sy=y;
                }
                else if(grid[x][y]==2)
                {
                    ex=x;
                    ey=y;
                }
                else
                c++;
            }
        }
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(sx,sy,ex,ey,c+1,grid,dp);
    }
};