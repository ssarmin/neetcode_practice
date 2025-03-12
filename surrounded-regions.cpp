//https://neetcode.io/problems/surrounded-regions
class Solution {
public:
    bool is_valid(vector<vector<char>>& board, int x, int y){
        if(x >= 0 && y >= 0 && x < board.size() && y < board[0].size()){
            return true;
        }
        return false;
    }
    void dfs(vector<vector<char>>& board, int x, int y){
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for(int i=0; i<4; i++){
            int r = x + dx[i];
            int c = y + dy[i];
            if(is_valid(board, r, c) && board[r][c] == 'O'){
                board[r][c] = 'N';
                dfs(board, r, c);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0; i<row; i++){
            if(board[i][0] == 'O'){
                board[i][0] = 'N';
                dfs(board, i, 0);
            }
            if(board[i][col-1] == 'O'){
                board[i][col-1] = 'N';
                dfs(board, i, col-1);
            }
        }

        for(int i=0; i<col; i++){
            if(board[0][i] == 'O'){
                board[0][i] = 'N';
                dfs(board, 0, i);
            }
            if(board[row-1][i] == 'O'){
                board[row-1][i] = 'N';
                dfs(board, row-1, i);
            }
        }

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] != 'N'){
                    board[i][j] = 'X';
                }else{
                    board[i][j] = 'O';
                }
            }
        }
    }
};

// Extra testcases:
// board=[["X","O","X","X"],["X","O","O","X"],["X","O","O","X"],["X","X","X","O"]]
// board=[["X"]]
// board=[["O"]]

