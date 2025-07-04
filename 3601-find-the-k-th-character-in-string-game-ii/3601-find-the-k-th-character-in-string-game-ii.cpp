class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k=k-1;
        int shift = 0;
        for(int i=0;i<operations.size();i++){
            if(i<60){
                if((k>>i) & 1) shift += operations[i];
            }
            //0-> no change, 1-> change
        
        }
        return 'a'+ shift%26;
    }
};