class Solution {
    
public:


    int maxScore(vector<int>&A, int total, int i,int j, vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        dp[i][j] = total - min(maxScore(A,total - A[i],i+1,j,dp),maxScore(A,total - A[j],i,j-1,dp));
        return dp[i][j];
    }

    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(21, vector<int>(21,-1));
        int total = 0;
        for(int x : nums) total += x;
        int ans = maxScore(nums,total,0,nums.size() - 1,dp);
        return ans >= total - ans;
    }
};