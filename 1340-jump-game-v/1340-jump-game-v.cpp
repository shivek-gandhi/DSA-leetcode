class Solution {
public:
    // int n;
    // vector<int> t;
    int solve(vector<int> &arr, int i,int d,vector<int>&dp){
        int n=arr.size();
        if(dp[i] != -1) return dp[i];
        int result = 1;

        //left
        for(int j=i-1;j>=max(0,i-d);j--){
            if(arr[j] >= arr[i]) break;
            result = max(result, 1 + solve(arr,j,d,dp));
        }
        //right
        for(int j=i+1;j<=min(n-1,i+d);j++){
            if(arr[j] >= arr[i]) break;
            result = max(result, 1 + solve(arr,j,d,dp));
        }
        return dp[i] = result;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n,-1);
        int result =1 ;
        for(int i=0;i<n;i++){
            result = max(result, solve(arr,i,d,dp));
        }
        return result;
    }
};