class Solution {
public:
    bool solve(int ind,int target, vector<int>&nums,vector<vector<int>> &dp){
        if(target ==0) return true;
        if(ind==0) return nums[0]==target;

        if(dp[ind][target] != -1) return dp[ind][target];

        bool notTaken = solve(ind-1,target, nums,dp);
        bool taken=false;
        if(nums[ind] <= target){
            taken = solve(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target] = taken || notTaken;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        if(sum % 2 ==1) return false;
        else{
            int k = sum/2;
            vector<vector<int>>dp(n,vector<int>(k+1,0));
            // return solve(n-1,k,nums,dp);
             for(int i=0;i<n;i++){
                dp[i][0] = true;
             }
             if(nums[0]<= k){
                dp[0][nums[0]]=true;
             }
             for(int ind = 1;ind<n;ind++){
                for(int target = 1;target<=k;target++){
                    bool notTaken = dp[ind - 1][target];
                    bool taken = false;
                    if (nums[ind] <= target) {
                        taken = dp[ind - 1][target - nums[ind]];
                    }
                    dp[ind][target] = notTaken || taken;
                }
             }
             return dp[n-1][k];
        }
        
    }
};