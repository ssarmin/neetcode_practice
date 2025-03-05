//https://neetcode.io/problems/max-area-of-island

class Solution {
public:
    bool is_valid(vector<vector<int>>& grid, int i, int j){
        if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size())
            return true;
        return false;
    }
    int bfs(vector<vector<int>>& grid, int x, int y){
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        grid[x][y] = 0;
        int area = 1;
        while(!q.empty()){
            int size = q.size();
            for(int s=0; s<size; s++){
                x = q.front().first;
                y = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    if(is_valid(grid, x+dx[k], y+dy[k]) && grid[x+dx[k]][y+dy[k]] == 1){
                        q.push(make_pair(x+dx[k], y+dy[k]));
                        grid[x+dx[k]][y+dy[k]] = 0;
                        area++;
                    }
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int area = bfs(grid, i, j);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};


// extra:
// grid=[[0,1,1,0,1],[1,0,0,0,1],[0,1,1,0,1],[0,1,0,0,1]]
// grid=[[0,1,1,0,1],[1,0,0,0,1],[0,1,1,0,1]]
// grid=[[0,1,1],[1,0,1],[0,1,1]]
// grid=[[0,1,1,0,1],[1,0,0,0,1],[0,1,1,0,1],[0,1,0,0,1],[0,1,1,0,1],[1,0,0,0,1],[0,1,1,0,1],[0,1,0,0,1]]
// grid=[[0,1,1,0,1],[0,1,1,0,1],[1,0,0,0,1],[0,1,1,0,1],[1,0,0,0,1],[0,1,1,0,1],[0,1,0,0,1],[0,1,1,0,1],[1,0,0,0,1],[0,1,1,0,1],[0,1,0,0,1]]


