class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 12345;

        int size = m * n;
        vector<int> arr;
        
        for (auto &row : grid) {
            for (int val : row) {
                arr.push_back(val % MOD);
            }
        }

        vector<int> prefix(size, 1), suffix(size, 1);

        for (int i = 1; i < size; i++) {
            prefix[i] = (prefix[i - 1] * arr[i - 1]) % MOD;
        }
        for (int i = size - 2; i >= 0; i--) {
            suffix[i] = (suffix[i + 1] * arr[i + 1]) % MOD;
        }

        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < size; i++) {
            int val = (prefix[i] * suffix[i]) % MOD;
            result[i / n][i % n] = val;
        }
        return result;
    }
};