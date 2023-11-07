// class Solution {
// public:
//     int f(int sx,int sy,int ex,int ey,int c,vector<vector<int>>&grid,vector<vector<int>>&dp)
//     {
//         if(sx<0 || sy<0 ||sx>=grid.size() || sy>=grid[0].size() || grid[sx][sy]==-1)
//             return 0;
//         if(sx==ex && sy==ey) {
//             if(c==0)
//                 return 1;
//             else
//                 return 0;
//         }
//         vector<int>dirx = {-1,0,1,0},diry = {0,1,0,-1};
//         int ans=0;
//         for(int i=0;i<4;i++) {
//             grid[sx][sy]=-1;
//             c--;
//             ans+=f(sx+dirx[i],sy+diry[i],ex,ey,c,grid,dp);
//             grid[sx][sy]=0;
//             c++;
//         }
//         return ans;
//     }
//     int uniquePathsIII(vector<vector<int>>& grid) {
//         int ans=0;
//         int c=0;
//         int n = grid.size(),m = grid[0].size();
//         int sx,sy,ex,ey;
//         for(int x=0;x<n;x++) {
//             for(int y=0;y<m;y++) {
//                 if(grid[x][y]==-1)
//                 continue;
//                 if(grid[x][y]==1) {
//                     sx=x;
//                     sy=y;
//                 }
//                 else if(grid[x][y]==2) {
//                     ex=x;
//                     ey=y;
//                 }
//                 else
//                 c++;
//             }
//         }
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return f(sx,sy,ex,ey,c+1,grid,dp);
//     }
// };
class Solution {
public:
   int count = 0; // Counter to keep track of the number of unique paths
   int zeroes = 0; // Counter to keep track of the number of empty cells

   void creator(vector<vector<int>>& grid, int row, int col, int length) {
       if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] == 3 || grid[row][col] == -1)
           return;

       if (grid[row][col] == 2 && zeroes == length) {
           count++;
           return;
       }

       int org = grid[row][col]; 
       grid[row][col] = 3;

       creator(grid, row + 1, col, length + 1);
       creator(grid, row - 1, col, length + 1);
       creator(grid, row, col + 1, length + 1);
       creator(grid, row, col - 1, length + 1);

       grid[row][col] = org; 
       return;
   }

   int uniquePathsIII(vector<vector<int>>& grid) {
       int row = 0;
       int col = 0; 
       int free = 0;

       for (int i = 0; i < grid.size(); i++) {
           for (int j = 0; j < grid[0].size(); j++) {
               if (grid[i][j] == 1) {
                   row = i; 
                   col = j;
                   free++;
               } else if (grid[i][j] == 0 || grid[i][j] == 2) {
                   free++;
               }
           }
       }

       zeroes = free;

       creator(grid, row, col, 1);

       return count; 
   }
};