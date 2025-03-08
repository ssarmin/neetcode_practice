// https://neetcode.io/problems/rotting-fruit
class Solution {
public:
    bool isValid(vector<vector<int>> grid, int i, int j){
        if(i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size())
            return true;
        return false;
    }
    void bfs(vector<vector<int>>& grid, int &count, vector<vector<bool>> &visit, queue<pair<int, int>> q){
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while(!q.empty()){
            int size = q.size();
            count++;
            for(int s=0; s<size; s++){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(int k=0; k<4; k++){
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(isValid(grid, x, y) && grid[x][y] != -1 && grid[x][y] != 0 && !visit[x][y]){
                        q.push(make_pair(x, y));
                        grid[x][y] = 2;
                        visit[x][y] = true;
                    }
                }
            }
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
        int count = -1;
        queue<pair<int, int>> q;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(grid[i][j] == 2 && !visit[i][j]){
                    q.push(make_pair(i, j));
                    visit[i][j] = true;
                }
            }
        }
        bfs(grid, count, visit, q);
        for(auto r: grid){
            for(auto c: r){
                if(c == 1)
                    return -1;
            }
        }
        if(count == -1)
            return 0;
        return count;
    }
};
// extra:
// [[1,1,0],[0,0,0],[0,1,2]]
// grid=[[1,2,0],[0,1,1],[0,1,2]]
// grid=[[1,2,0],[0,1,1],[0,1,2],[1,1,0],[1,1,1],[0,1,2]]
// grid=[[0]]
