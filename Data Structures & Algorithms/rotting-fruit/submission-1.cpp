class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& time, int i , int j, int currentTime)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || currentTime >= time[i][j]) return;
        time[i][j] = currentTime;
        dfs(grid, time, i+1, j, currentTime+1);
        dfs(grid, time, i-1, j, currentTime+1);
        dfs(grid, time, i, j+1, currentTime+1);
        dfs(grid, time, i, j-1, currentTime+1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return -1;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> time(rows, vector<int> (cols, INT_MAX));
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 2) dfs(grid, time, i, j, 0);
            }
        }
        int timeReq = 0;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(grid[i][j] == 1)
                {
                    if(time[i][j] == INT_MAX) return -1;
                    timeReq = max(timeReq, time[i][j]);
                }
            }
        }
        return timeReq;
    }
};
