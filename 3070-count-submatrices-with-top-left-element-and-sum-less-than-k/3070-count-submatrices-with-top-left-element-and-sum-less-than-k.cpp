class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int sum = 0;
        vector<vector<int>> store;
        for(int i=0;i<m;i++){
            vector<int> temp(n);
            sum = grid[i][0];
            temp[0]=sum;
            for(int j=1;j<n;j++){
                sum+=grid[i][j];
                temp[j]=sum;
            }
            store.push_back(temp);
        }
        int ans=0;
        int ref=-1;
        for(int i=0;i<n;i++){
            if(store[0][i]>k){
                ref=i;
                break;
            }
            else{
                continue;
            }
        }
        for(int i=0;i<n;i++){
            int temp= store[0][i];
            if(temp<=k){
                ans++;
            }
            for(int j=1;j<m;j++){
               temp+=store[j][i];
               if(temp<=k){
                ans++;
               }
               else{
                break;
               }
            }
        }
        return ans;
    }
};