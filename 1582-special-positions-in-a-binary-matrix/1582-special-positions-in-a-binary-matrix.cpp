class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n=mat[0].size();
        int count=0;
        // for(int i=0;i<m;i++){
        //     for(int j=0;i<n;j++){
        //         // if(mat[i][j] ==0) continue;

        //         bool special= true;
        //         //check column
        //         for(int r=0;r<m;r++){
        //             if(r!=i && mat[r][j]==1){
        //                 special=false;
        //                 break;
        //             }
        //         }

        //         //check row
        //         for(int c=0;c<n;c++){
        //             if(c !=j && mat[i][c]==1){
        //                 special=false;
        //                 break;
        //             }
        //         }

        //         if(special == true){
        //             count++;
        //         }
        //     }
        // }
        // return count;

        vector<int> rowCount(m,0);
        vector<int> colCount(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] == 1){
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    continue;
                }
                if(rowCount[i]==1 && colCount[j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};