class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n=grid[0].size();

        vector<vector<int>> CumSumX(m,vector<int>(n,0));
        vector<vector<int>> CumSumY(m,vector<int>(n,0));
        int count = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                CumSumX[i][j] = (grid[i][j] == 'X');
                CumSumY[i][j] = (grid[i][j] == 'Y');

                if(i-1>=0){
                    CumSumX[i][j] += CumSumX[i-1][j];
                    CumSumY[i][j] += CumSumY[i-1][j];
                }
                
                if(j-1 >=0){
                    CumSumX[i][j] += CumSumX[i][j-1];
                    CumSumY[i][j] += CumSumY[i][j-1];
                }

                if(i-1>=0 && j-1>=0){
                    CumSumX[i][j] -= CumSumX[i-1][j-1];
                    CumSumY[i][j] -= CumSumY[i-1][j-1];
                }
                
                if(CumSumX[i][j] == CumSumY[i][j] && CumSumX[i][j] >0){
                    count++;
                }
            }
        }
        return count;
    }
};