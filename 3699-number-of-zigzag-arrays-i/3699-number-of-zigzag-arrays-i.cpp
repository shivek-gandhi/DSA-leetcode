class Solution {
public:
    static const int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int numValues = r - l + 1;

        if (n == 1) return numValues;
        if (numValues == 1) return 0;

        vector<int> up(numValues), down(numValues);
        vector<int> prefixUp(numValues), prefixDown(numValues);
        vector<int> nextUp(numValues), nextDown(numValues);

        // length = 2
        for (int value = 0; value < numValues; value++) {
            up[value] = value;
            down[value] = numValues - value - 1;
        }

        if (n == 2) {
            long long ans = 0;
            for (int value = 0; value < numValues; value++) {
                ans = (ans + up[value] + down[value]) % MOD;
            }
            return ans;
        }

        for (int len = 3; len <= n; len++) {

            prefixUp[0] = up[0];
            prefixDown[0] = down[0];

            for (int value = 1; value < numValues; value++) {
                prefixUp[value] = (prefixUp[value - 1] + up[value]) % MOD;
                prefixDown[value] = (prefixDown[value - 1] + down[value]) % MOD;
            }

            int totalUp = prefixUp[numValues - 1];

            for (int value = 0; value < numValues; value++) {

                // previous move was down, current move goes up
                nextUp[value] = (value == 0 ? 0 : prefixDown[value - 1]);

                // previous move was up, current move goes down
                nextDown[value] = (totalUp - prefixUp[value] + MOD) % MOD;
            }

            swap(up, nextUp);
            swap(down, nextDown);
        }

        long long ans = 0;
        for (int value = 0; value < numValues; value++) {
            ans = (ans + up[value] + down[value]) % MOD;
        }

        return ans;
    }
};