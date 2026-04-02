class Solution {
public:
    int maximumAmount(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // dp[r][c][k] -> max coins from (r,c) with k neutralizations left
        vector dp(rows, vector(cols, vector<int>(3, INT_MIN)));

        // base case (bottom-right cell)
        for (int k = 0; k < 3; k++) {
            if (k > 0)
                dp[rows-1][cols-1][k] = max(0, grid[rows-1][cols-1]);
            else
                dp[rows-1][cols-1][k] = grid[rows-1][cols-1];
        }

        // fill table
        for (int r = rows - 1; r >= 0; r--) {
            for (int c = cols - 1; c >= 0; c--) {

                if (r == rows-1 && c == cols-1) continue;

                for (int k = 0; k < 3; k++) {

                    int best = INT_MIN;

                    if (r + 1 < rows)
                        best = max(best, dp[r+1][c][k]);
                    if (c + 1 < cols)
                        best = max(best, dp[r][c+1][k]);

                    int curr = grid[r][c] + best;

                    // try skipping negative
                    if (grid[r][c] < 0 && k > 0) {
                        int skip = INT_MIN;

                        if (r + 1 < rows)
                            skip = max(skip, dp[r+1][c][k-1]);
                        if (c + 1 < cols)
                            skip = max(skip, dp[r][c+1][k-1]);

                        curr = max(curr, skip);
                    }

                    dp[r][c][k] = curr;
                }
            }
        }

        return dp[0][0][2];
    }
};