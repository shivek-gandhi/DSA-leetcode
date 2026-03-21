class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int startRow =x;
        int endRow= x+k-1;

        int startCol = y;
        int endCol = y+k-1;

        while(startRow<endRow){
            for(int j=startCol; j<= endCol;j++){
                swap(grid[startRow][j],grid[endRow][j]);
            }
            startRow++;
            endRow--;
        }
        return grid;
    }
};