class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCost, vector<int>& colCost) {
        int r1 = startPos[0], c1 = startPos[1];
        int r2 = homePos[0], c2 = homePos[1];

        int result = 0;

        //move in rows
        if(r2 >= r1){
            //moving down
            for(int r = r1 + 1;r<= r2; r++){
                result += rowCost[r];
            }
        }
        else{
            //moving up
            for(int r = r1- 1;r>= r2;r--){
                result += rowCost[r];
            }
        }

        if(c2 >= c1){
            //moving right
            for(int c= c1 + 1;c<= c2;c++){
                result += colCost[c];
            }
        }
        else{
            //moving left
            for(int c = c1-1;c >= c2; c--){
                result += colCost[c];
            }
        }
        return result;
    }
};