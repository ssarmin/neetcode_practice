//https://neetcode.io/problems/set-zeroes-in-matrix
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false;
        bool firstCol = false;

        for(int c=0; c < matrix[0].size(); c++){
            if(matrix[0][c] == 0){
                firstRow = true;
                break;
            }
        }

        for(int r=0; r < matrix.size(); r++){
            if(matrix[r][0] == 0){
                firstCol = true;
                break;
            }
        }

        for(int r=1; r<matrix.size(); r++){
            for(int c=1; c<matrix[0].size(); c++){
                if(matrix[r][c] == 0){
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }

        for(int c=1; c<matrix[0].size(); c++){
            if(matrix[0][c] == 0){
                for(int r=1; r<matrix.size(); r++){
                    matrix[r][c] = 0;
                }
            }
        }

        for(int r=1; r<matrix.size(); r++){
            if(matrix[r][0] == 0){
                for(int c=1; c<matrix[0].size(); c++){
                    matrix[r][c] = 0;
                }
            }
        }

        if(firstRow){
            for(int c=0; c<matrix[0].size(); c++){
                matrix[0][c] = 0;
            }
        }

        if(firstCol){
            for(int r=0; r<matrix.size(); r++){
                matrix[r][0] = 0;
            }
        }
    }
};

// [[-4,-2147483648,6,-7,0],[-8,6,-8,-6,0],[2147483647,2,-9,-6,-10]]
// [[3,5,5,6,9,1,4,5,0,5],[2,7,9,5,9,5,4,9,6,8],[6,0,7,8,1,0,1,6,8,1],[7,2,6,5,8,5,6,5,0,6],[2,3,3,1,0,4,6,5,3,5],[5,9,7,3,8,8,5,1,4,3],[2,4,7,9,9,8,4,7,3,7],[3,5,2,8,8,2,2,4,9,8]]
// [[0,1,2,0],[3,4,-1,-1],[1,3,1,5]]
