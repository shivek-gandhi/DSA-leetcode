class Solution {
public:

    int find(vector<vector<int>> &grid,int i,int j, int k){

        int n=grid.size();
        int m=grid[0].size();

        if(i+ 2*k >=n ||j+k >= m || j-k<0) return -1;

        int r = i;
        int c=j;
        int sum=0;

        //top-> left
        for(int l=0;l<k;l++){
            sum += grid[r+l][c-l];
        }

        //left->bottom
        r=i+k;
        c=j-k;

        for(int l=0;l<k;l++){
            sum +=grid[r+l][c+l];
        }
        

        //bottom->right
        r = i + 2*k;
        c=j;

        for(int l=0;l<k;l++){
            sum += grid[r-l][c+l];
        }

        //right->top
        r=i+k;
        c=j+k;
        for(int l=0;l<k;l++){
            sum+= grid[r-l][c-l];
        }

        return sum;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        priority_queue<int,vector<int>,greater<int>> pq;
        set<int> st;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){

                if(st.insert(grid[i][j]).second){
                    pq.push(grid[i][j]);
                    if(pq.size() >3) pq.pop();
                }

                for(int k=1;k< (min(row,col)/2)+1;k++){
                    int val = find(grid,i,j,k);
                    if(val== -1) break;

                    if(st.insert(val).second){
                        pq.push(val);
                        if(pq.size()>3) pq.pop();
                    }
                }
            }
        }
        int n=pq.size();
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            ans[i] = pq.top();
            pq.pop();
        }
        return ans;
    }
};