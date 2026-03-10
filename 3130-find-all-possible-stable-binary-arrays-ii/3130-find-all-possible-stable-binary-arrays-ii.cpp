class Solution {
public:
    const int MOD = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {

        vector<vector<vector<int>>> dp(
            zero+1, vector<vector<int>>(one+1, vector<int>(2,0)));

        for(int z=1; z<=min(limit, zero); z++)
            dp[z][0][0] = 1;

        for(int o=1; o<=min(limit, one); o++)
            dp[0][o][1] = 1;

        for(int z=1; z<=zero; z++){
            for(int o=1; o<=one; o++){

                long long val0 = dp[z-1][o][0] + dp[z-1][o][1];
                if(z-limit-1 >= 0)
                    val0 -= dp[z-limit-1][o][1];

                dp[z][o][0] = (val0 % MOD + MOD) % MOD;

                long long val1 = dp[z][o-1][0] + dp[z][o-1][1];
                if(o-limit-1 >= 0)
                    val1 -= dp[z][o-limit-1][0];

                dp[z][o][1] = (val1 % MOD + MOD) % MOD;
            }
        }

        return (dp[zero][one][0] + dp[zero][one][1]) % MOD;
    }
};