class Solution {
public:
    int alternateDigitSum(int n) {
        int sum = 0;
        int multiplier = 1;
        // while(n>0){
        //     sum += multiplier * (n%10);
        //     n = n / 10;
        //     multiplier *= (-1);
        // }
        // return sum;
        string s = to_string(n);
        int len = s.length();
        for(int i = 0;i<len;i++){
            
            sum += multiplier * (s[i] - '0');
            multiplier *= (-1);
        }
        return sum;
    }
};