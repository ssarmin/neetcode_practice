//https://neetcode.io/problems/islands-and-treasure
class Solution {
public:
    bool isValid(vector<vector<int>> grid, int i, int j){
        if(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size())
            return true;
        return false;
    }
    void bfs(vector<vector<int>>& grid, int i, int j){
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        visit[i][j] = true;
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            count++;
            for(int s=0; s<size; s++){
                i = q.front().first;
                j = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(isValid(grid, x, y) && grid[x][y] != -1 && grid[x][y] != 0 && !visit[x][y]){
                        q.push(make_pair(x, y));
                        grid[x][y] = min(count, grid[x][y]);
                        visit[x][y] = true;
                    }
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 0){
                    bfs(grid, i, j);
                }
            }
        }
    }
};
